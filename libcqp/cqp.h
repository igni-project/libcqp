#ifndef _LIBCQP_CQP_H
#define _LIBCQP_CQP_H 1

enum {
	CQP_REQ_CODE_CAST_POINT = 0,
	CQP_REQ_CODE_CAST_RAY
};

#ifdef __cplusplus
extern "C" {
#endif

int cqp_cast_point(
		int fd,
		float x,
		float y,
		float z
		);

int cqp_cast_ray(
		int fd,
		float x_origin,
		float y_origin,
		float z_origin,
		float x_vector,
		float y_vector,
		float z_vector
		);

#ifdef __cplusplus
}
#endif

#endif
