
void rotation270(int **a, int **b, unsigned int  c, unsigned int  r) {
	//cout << "rotation270"<< ", c:"<<c<<", r:"<<r<<endl<<endl;
	for (unsigned int i = 0; i < c; i++)
	{
		for (unsigned int j = 0; j < r; j++)
		{
			//cout << "rotation270"<< " , "<< c - i-1 <<" ,"<< j <<" ,"<< j <<" ,"<< i <<endl;
			b[c - i - 1][j] = a[j][i];
		}
	}
}

void rotation180(int **a, int **b, unsigned int  c, unsigned int  r) {
	//cout << "rotation180"<< ", c:"<<c<<", r:"<<r<<endl<<endl;
	for (unsigned int i = 0; i < c; i++)
	{
		for (unsigned int j = 0; j < r; j++)
		{
			//cout << "rotation180"<< " , "<< r - j-1 <<" ,"<< c - i-1 <<" ,"<< j <<" ,"<< i <<endl;
			b[r - j - 1][c - i - 1] = a[j][i];
		}
	}
}

void rotation90(int **a, int **b, unsigned int  c, unsigned int  r) {
	//cout << "rotation90"<< ", c:"<<c<<", r:"<<r<<endl<<endl;
	for (unsigned int i = 0; i < c; i++)
	{
		for (unsigned int j = 0; j < r; j++)
		{
			//cout << "rotation90"<< " , "<<  i <<" ,"<< r - j -1<<" ,"<< j <<" ,"<< i <<endl;
			b[i][r - j - 1] = a[j][i];
		}
	}
}
#pragma once
