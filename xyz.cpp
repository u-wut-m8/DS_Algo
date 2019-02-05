#include <iostream>
#include <climits>

int main(int argc, char *argv[]){
	int T, N, M, temp, one_count, zero_count, ind, min;
	std::cin>>T;
	while(T--){
		std::cin>>N>>M;
		ind = -1;
		min = INT_MAX;
		for(int i=0;i<N;i++){
			zero_count = 0;
			one_count = 0;
			for(int j=0;j<M;j++){
				std::cin>>temp;
				if(temp&1)
					zero_count++;
				else
					one_count++;
			}
			if(zero_count == M)
				continue;
			if(one_count < min){
				min = one_count;
				ind = i;
			}
		}
		std::cout<<ind<<std::endl;
	}
	return 0;
}