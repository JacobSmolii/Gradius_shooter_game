#ifndef F_P_SEC_H
#define F_P_SEC_H

# include <time.h>
# define NSEC_IN_SEC 1000000000L

class Frame_psec
{

	public:
		Frame_psec();
		~Frame_psec();
		Frame_psec(const Frame_psec & src);
		float get_fps_cout() const;

		int frame_per_second(void);
		Frame_psec & operator=(const Frame_psec & src);


	private:
		int _fps;
		long _Interval;
		float _fps_count;
		struct timespec _nextUpdateAt;
		struct timespec _lastUpdateAt;
};

long			time_subtract(struct timespec a, struct timespec b);
struct timespec	time_add(struct timespec t, long n);

#endif
