#include <iostream>
#include <climits>

int main(int argc, char *argv[]) {
	int T, N, **arr, M;
	int up, down, left, right;
	std::cin>>T;
	while(T--) {
		std::cin>>N;
		arr = new int*[N];
		for(int i=0;i<N;i++)
			arr[i] = new int[N];
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				std::cin>>*(*(arr+i)+j);
		up = arr[N>>1][N>>1];
		M = N;
		for(int i=0;i<N/2;i++){
			for(int j=0;j<M;j++)
				if(i<=j)
					up += arr[i][j];
			M--;
		}
		down = arr[N>>1][N>>1];
		M = N;
		for(int i=N-1;i>N/2;i--){
			for(int j=M-1;j>=0;j--)
				if(i+j>=N-1)
					down += arr[i][j];
			M--;
		}
		left = arr[N>>1][N>>1];
		M = N;
		for(int i=M-1;i>=0;i--){
			for(int j=0;j<N/2;j++)
				if(i>=j)
					std::cout<<arr[i][j]<<" ";
			std::cout<<std::endl;			
			M--;
		}
		std::cout<<left<<std::endl;
		for(int i=0;i<N;i++)
			delete[] arr[i];
		delete[] arr;
	}
	return 0;
}