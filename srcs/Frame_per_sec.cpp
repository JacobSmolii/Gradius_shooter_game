/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame_per_sec.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:40:30 by vsmolii           #+#    #+#             */
/*   Updated: 2019/11/06 16:20:34 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Frame_per_sec.hpp"

Frame_psec::Frame_psec() : _fps(60), _fps_count(0)
{
	this->_Interval = NSEC_IN_SEC / this->_fps;
	clock_gettime(CLOCK_REALTIME, &(this->_nextUpdateAt));
}

Frame_psec::Frame_psec(const Frame_psec & data) : _fps(data._fps), _Interval(data._Interval), \
	 _fps_count(data._fps_count), _nextUpdateAt(data._nextUpdateAt), _lastUpdateAt(data._lastUpdateAt)
{}
Frame_psec::~Frame_psec() {}

int Frame_psec::frame_per_second(void)
{
	struct timespec	now;
	clock_gettime(CLOCK_REALTIME, &now);
	long diff = time_subtract(now, this->_nextUpdateAt);
	if (diff > 0)
	{
		this->_fps_count = (float)NSEC_IN_SEC / time_subtract(this->_nextUpdateAt, this->_lastUpdateAt);
		this->_lastUpdateAt = this->_nextUpdateAt;
		if (diff > this->_Interval)
			this->_nextUpdateAt = now;
		else
			this->_nextUpdateAt = time_add(this->_nextUpdateAt, this->_Interval);
		return true;
	}
	return false;
}

float Frame_psec::get_fps_cout() const
{
	return this->_fps_count;
}

Frame_psec & Frame_psec::operator=(const Frame_psec & data)
{
	this->_fps = data._fps;
	this->_Interval = data._Interval;
	this->_fps_count = data._fps_count;
	this->_nextUpdateAt = data._nextUpdateAt;
	this->_lastUpdateAt = data._lastUpdateAt;
	return *this;
}


long time_subtract(struct timespec a, struct timespec b)
{
	return ((a.tv_sec - b.tv_sec) * NSEC_IN_SEC + a.tv_nsec - b.tv_nsec);
}

struct timespec	time_add(struct timespec t, long n)
{
	t.tv_nsec += n;
	while (t.tv_nsec < 0)
	{
		t.tv_sec--;
		t.tv_nsec += NSEC_IN_SEC;
	}
	while (t.tv_nsec > NSEC_IN_SEC)
	{
		t.tv_sec++;
		t.tv_nsec -= NSEC_IN_SEC;
	}
	return (t);
}

