#include <iostream>
#define size 6
using namespace std;
struct node{
	int fr, to, cost;
}p[size];
void prims(int b[][size+1]){
	int a[size + 1], c = 0, temp1 = 0, temp = 0;
	a[0] = 1;
	while (c < size){
		int min = 999;
		for (int i = 0; i < size+1; i++){
			if (a[i] == 1){
				for (int j = 0; j < size+1; ){
					if (b[i][j] >= min || b[i][j] == 0){
						j++;
					}
					else if (b[i][j] < min){
						min = b[i][j];
						temp = i;
						temp1 = j;
					}
				}
			}
		}
		a[temp1] = 1;
		p[c].fr = temp;
		p[c].to = temp1;
		p[c].cost = min;
		c++;
		b[temp][temp1] = b[temp1][temp] = 1000;
	}
	for (int k = 0; k < size; k++){
		cout << "source node:" << p[k].fr << endl;
		cout << "destination node:" << p[k].to << endl;
		cout << "weight of node" << p[k].cost << endl;
	}
}
void main(){
	int b[size + 1][size + 1];
	for (int i = 0; i < size+1; i++){
		cout << "enter values for " << (i + 1) << " row\n";
		for (int j = 0; j < size+1; j++)
			cin >> b[i][j];
	}
	prims(b);
}