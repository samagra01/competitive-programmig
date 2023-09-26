class Monoqueue
{
	deque<pair<int, int>> m_deque; //pair.first: the actual value,
	//pair.second: how many elements were deleted between it and the one before it.
public:
	void push(int val)
	{
		int count = 0;
		while (!m_deque.empty() && m_deque.back().first < val)
		{
			count += m_deque.back().second + 1;
			m_deque.pop_back();
		}
		m_deque.emplace_back(val, count);
	};
	int max()
	{
		if (m_deque.empty())return 0;
		return m_deque.front().first;
	}
	void pop ()
	{
		if (m_deque.front().second > 0)
		{
			m_deque.front().second --;
			return;
		}
		m_deque.pop_front();
	}
};


struct Monotone_queue {
	deque<int> dq;

	void insert(int val) {
		while (!dq.empty() && dq.back() < val) {
			dq.pop_back();
		}
		dq.push_back(val);
	}
	void remove(int val) {
		if (val == dq.front()) {
			dq.pop_front();
		}
	}
	int Maxi() {
		return dq.front();
	}

};
