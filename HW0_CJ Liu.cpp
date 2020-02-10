#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

// Create a list of 'size' floating point numbers in the range [-bound, bound]
vector<double> generate_random_list(int size, int bound) {
	vector<double> v;
	int LO = -bound;
	int HI = bound;
	for(int i=0;i<size;i++) {
		v.push_back(LO + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(HI-LO))));
	}
	return v;
}

//Update position by velocity, one time-step
void update_coordinates(vector<double> &xs, vector<double> &ys, 
		vector<double> &zs, vector<double> &vx, vector<double> &vy, vector<double> &vz) {
			
	for(int i=0;i<xs.size();i++){
		xs[i] = xs[i] + vx[i];
        ys[i] = ys[i] + vy[i];
        zs[i] = zs[i] + vz[i];
	}
}

// Main:
int main(int argc, char** argv) {
	if(argc != 3) {
		cout<<"Required arguments: vector_length(N) and iterations_num(M)";
		exit(-1);
	}
	
	int size = atoi(argv[1]);
	int iter = atoi(argv[2]);
	
	srand(size);
	vector<double> xs, ys, zs, vx, vy, vz;
	xs = generate_random_list(size, 1000);
	ys = generate_random_list(size, 1000);
	zs = generate_random_list(size, 1000);
	vx = generate_random_list(size, 1);
	vy = generate_random_list(size, 1);
	vz = generate_random_list(size, 1);
	
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start); 
  
    // unsync the I/O of C and C++. 
    ios_base::sync_with_stdio(false); 
  
    for(int i=0;i<iter;i++) {
		update_coordinates(xs, ys, zs, vx, vy, vz);
	}
    // stop timer. 
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end); 
    // clock_gettime(CLOCK_REALTIME, &end); 
    clock_gettime(CLOCK_MONOTONIC, &end); 
	
	
	double chksum = 0;
	for(int i=0;i<size;i++){
		chksum += xs[i];
		chksum += ys[i];
		chksum += zs[i];
	}
    // Calculating total time taken by the program. 
    double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-3;
	time_taken = (time_taken / (size * iter) );
	cout << "Mean time per coordinate: " << fixed << time_taken << setprecision(9) << " us" << endl;
	cout << "Final checksum is: " << chksum << endl;
	return 0;
}