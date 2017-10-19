/*
 * ring.h
 *
 *  Created on: Jun 23, 2016
 *      Author: johnpurcell
 */

#ifndef RING_H_
#define RING_H_

#include <iostream>

using namespace std;

template<class T>
class ring {

private:
	int m_pos;
	int m_size;
	T *m_values;

public:
	class iterator;

public:
	ring(int size) :
			m_pos(0), m_size(size), m_values(nullptr) {
		m_values = new T[size];
	}

	~ring() {
		delete[] m_values;
	}

	int size() {
		return m_size;
	}

	iterator begin() {
		return iterator(0, *this);
	}

	iterator end() {
		return iterator(m_size, *this);
	}

	void add(T value) {
		m_values[m_pos++] = value;

		if (m_pos == m_size) {
			m_pos = 0;
		}
	}

	T &get(int pos) {
		return m_values[pos];
	}
};

template<class T>
class ring<T>::iterator {
private:
	int m_pos;
	ring &m_ring;
public:
	iterator(int pos, ring &ring_ref) :
			m_pos(pos), m_ring(ring_ref) {

	}

	//Post fix
	/*
	 * This differs from what's in at least the original
	 * version of the tutorial video. Really we should
	 * return a version of the iterator as it was
	 * before it was modified, for consistency with
	 * the usual behaviour of the postfix operator.
	 */
	iterator operator++(int) {

		iterator old = *this;
		++(*this);
		return old;
	}

	//prefix
	iterator& operator++() {
		++m_pos;

		return *this;
	}

	T& operator*() {
		return m_ring.get(m_pos);
	}

	bool operator==(const iterator &other) const {
		return m_pos == other.m_pos;
	}

	bool operator!=(const iterator &other) const {
		return !(*this == other);
	}

};

#endif /* RING_H_ */
