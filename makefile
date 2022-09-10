all: collection-test.cpp Collection.h Stress_ball_test.cpp Stress_ball_test.h Stress_ball.cpp Stress_ball.h Jeans_test.cpp Jeans_test.h Jeans.cpp Jeans.h
	g++ -std=c++11 -c Stress_ball_test.cpp
	g++ -std=c++11 -c Jeans_test.cpp
	g++ -std=c++11 -c Stress_ball.cpp
	g++ -std=c++11 -c Jeans.cpp
	g++ -std=c++11 -c collection-test.cpp
	g++ -std=c++11 -o test *.o
clean:
	rm test *.o
run: test
	./test