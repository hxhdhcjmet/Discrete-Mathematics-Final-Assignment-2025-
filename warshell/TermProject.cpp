#include<iostream>
#include<vector>
using namespace std;
//使用warshell算法判断关系是否是传递的
bool warshell(vector<vector<bool>>& rmatrix) {
	int n = rmatrix.size();
	vector<vector<bool>> temp = rmatrix;
	if (n == 0 || n == 1) return true;//零元和一元一定是传递的
	for (int k = 0;k < n;k++) {
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				rmatrix[i][j] = rmatrix[i][j] || (rmatrix[i][k] && rmatrix[k][j]);
			}
		}
	}
	return rmatrix == temp;//传递闭包与原矩阵相等，则原关系是传递的
}
void isTransitive(vector<vector<bool>>& rmatrix) {//判断输入的任意一个n阶01方阵对应的二元关系是否是传递的
	bool flag = warshell(rmatrix);
	if (flag) {
		cout << "Transitive!" << endl;
		return;
	}
	cout << "Not Transitive" << endl;
}


int CountTranRelation(int n=4){//计算n元集合上的传递关系数目,输入集合大小n,默认为4
	int count=0;
	 for(int k=0;k<(1<<(n*n));k++){//构建n元集合上的所有可能的关系矩阵
        vector<vector<bool>> matrix(n,vector<bool>(n,false));//初始化为全0
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int bitPos=i*n+j;
                matrix[i][j]=(k>>bitPos)&1;//n元集合上的关系矩阵有2^(n^2)种,与n^2长01序列之间存在双射关系,据此构造关系矩阵
            }
        }
        if(warshell(matrix)){
            ++count;
        }
    }
	return count;
}
int main() {
	int n,count;
	cout<<"Enter the scale of the set:"<<endl;
	cin>>n;
	count=CountTranRelation(n);
    cout<<"the number of transitive relations on an "<<n<<"-element set is:"<<count<<endl;
	return 0;
}