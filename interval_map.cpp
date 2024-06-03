#include <map>
template <typename K, typename V>
class interval_map
{
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K, V> m_map;

public:
	// constructor associates whole range of K with val
	interval_map(V const &val)
		: m_valBegin(val)
	{
	}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign(K const &keyBegin, K const &keyEnd, V const &val)
	{
		// INSERT YOUR SOLUTION HERE
		// SOLUTION:

		if (!(keyBegin < keyEnd))
		{
			return;
		}

		auto start = m_map.lower_bound(keyBegin);
		auto stop = m_map.lower_bound(keyEnd);

		if (start != m_map.begin() && std::prev(start)->second == val)
		{
			start = std::prev(start);
		}
		else
		{
			m_map[keyBegin] = val;
		}

		m_map.erase(start, stop);

		if (stop == m_map.end() || stop->first != keyEnd)
		{
			m_map[keyEnd] = stop == m_map.end() ? m_valBegin : stop->second;
		}

		auto in = m_map.find(keyBegin);
		while (in != m_map.end())
		{
			auto next_id = std::next(in);
			if (next_id != m_map.end() && in->second == next_id->second)
			{
				m_map.erase(next_id);
			}
			else
			{
				in = next_id;
			}
		}
	}

	// look-up of the value associated with key
	V const &operator[](K const &key) const
	{
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin())
		{
			return m_valBegin;
		}
		else
		{
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.