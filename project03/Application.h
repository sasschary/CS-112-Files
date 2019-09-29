/*
 * Application.h declares the methods for the Application class.
 * Student Name: Zachary Clark and Christian Mutschler
 * Date: 9-27-19
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Vec.h"

class Application {
public:
	void run();

private:
	Vec parsePoint(string ptInput);
	Vec inputNewVector();
	unsigned dims = 0;

};

#endif /* APPLICATION_H_ */
