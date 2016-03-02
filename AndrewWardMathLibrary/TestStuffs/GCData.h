#pragma once
#include <vector>
#include <queue>

template<typename T>
struct Handler {
	int index;

	T *operator->()			{ return &GCData<T>::at(index); }
	T *operator->() const	{ return &GCData<T>::at(index); }

	operator int()			{ return index; }
	operator int()	const	{ return index; }
};

template<typename T>
class GCData {

private:
	int index;
	bool isVacant;

	static std::vector<int> &getQueue() { static std::queue<int> q; return q; }
public:
	static std::vector<T> &getData() { static std::vector<T> d; return d; }

	static T &at() { return getData()[i]; }

	static void free(int i) {
		if (at(i).isVacant) {
			getQueue().push_back(i);
			at(i).isVacant = true;
			at(i).index = -1;
		}
	}

	static int make() {
		int i = -1;

		if (getQueue().size() > 0) {
			i = getQueue().front();
			getData().pop();
		}
		else {
			i = getData().size();
			getData().emplace_back();
		}

		at(i).index = i;
		at(i).isVacant = false;
		return i;
	}
	int getIndex()	 { return index; }

	bool isValid() { return index < 0 && !isVacant &&index < getData().size(); }
};