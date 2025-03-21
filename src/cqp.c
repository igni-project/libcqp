#include "cqp.h"

#include <sys/socket.h>

int cqp_cast_point(
		int fd,
		float x,
		float y,
		float z
		)
{
	/* The request contains:
	 * 	a 1-byte request code	(1) = 1
	 * 	3 4-byte floats			(3 * 4) = 12.
	 *
	 * The total size of the request is 13.	(12 + 1) */
	char req[13];

	/* Request code field has an offset of 0 */
	req[0] = CQP_REQ_CODE_CAST_POINT;

	/* With an offset of 1, X location */
	*(float*)&req[1] = x;
	*(float*)&req[5] = y; /* +4 to offset */
	*(float*)&req[9] = z; /* +4 to offset*/

	if (send(fd, req, sizeof(req), 0) == -1)
	{
		return -1;
	}

	return 0;
}

int cqp_cast_ray(
		int fd,
		float x_origin,
		float y_origin,
		float z_origin,
		float x_vector,
		float y_vector,
		float z_vector
		)
{
	/* The request contains:
	 * 	a 1-byte request code	(1) = 1
	 * 	3 4-byte floats			(6 * 4) = 24.
	 *
	 * The total size of the request is 25.	(24 + 1) */
	char req[25];

	/* Request code field has an offset of 0 */
	req[0] = CQP_REQ_CODE_CAST_RAY;

	/* With an offset of 1, X origin */
	*(float*)&req[1] = x_origin;
	*(float*)&req[5] = y_origin; /* +4 to offset */
	*(float*)&req[9] = z_origin; /* +4 to offset*/
	*(float*)&req[13] = x_vector; /* +4 to offset */
	*(float*)&req[17] = y_vector; /* +4 to offset */
	*(float*)&req[21] = z_vector; /* +4 to offset*/

	if (send(fd, req, sizeof(req), 0) == -1)
	{
		return -1;
	}

	return 0;
}
