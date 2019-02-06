#include <iostream>
#include <climits>

int main(int argc, char *argv[]) {
	int T, M, N, temp, count, prev, ind;
	std::cin>>T;
	while(T--) {
		std::cin>>N>>M;
		prev = INT_MIN;
		ind = -1;
		for(int i=0;i<N;i++){
			count = 0;
			for(int j=0;j<M;j++){
				std::cin>>temp;
				if(temp == 1)
					count++;
			}
			if(count > prev){
				prev = count;
				ind = i;
			}
		}
		std::cout<<ind<<std::endl;
	}
	return 0;
}