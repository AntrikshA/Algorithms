//conv.cpp

#include <iostream>
#include <vector>
using namespace std;

class matrix{
private:
	vector<vector<vector<int> > > vec3d(1, vector<vector<int> >(1, vector<int>(1)));
public:
	matrix(int depth, int width, int length){
		vec3d.resize(depth,vector<vector<int> >(width,vector<int>(length)));
		// return vec3d;
	}

	view(){
		for (int i = 0; i < matrix[0][0].size(); ++i)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				for (int k = 0; k < matrix.size(); k++)
				{
					cout << matrix[i][j][k] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
	}

	friend matrix operator*(matrix & out, const matrix & m1, const matrix & m2);

};

matrix operator *(matrix & out, const matrix & m1, const matrix & m2) {
   out.view();
   return out;
}

class conv
{
public:
	conv(){
		// cout << matrix[0] * matrix[1];
	}
	~conv();
	

	vector <int> convolution(int filter_dim, int pad){
		std::vector<int> c;
		std::vector<std::vector<int> > filter;

		return c;
	}
	
};


int main(){
	// vector<vector<vector<int> > > matrix;
	matrix mat(10,10,10);
	cout << mat;
	return 0;
}

