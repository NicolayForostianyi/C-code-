#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;
class nood {
	class dots {
	public:
		vector<int>mases;
		int num;
		bool work;
		vector<dots*> threeds;
		dots *parrent;
		int glob_ms;
};
	

	dots **dt;
	int size;
public:
	nood(){
		cout << "введите количество точек графа" << endl;
		int u;
		cin >> u;
		cin.get();
		this->size = u;
		dt = new dots*[u];
		
		for (int i(0); i < u; i++) {
			dt[i] = new dots;
		}
		
		for (int i(0); i < u; i++) {
			
			dt[i]->work = false;
			dt[i]->num = i;
			dt[i]->glob_ms = 99999999;
			cout << "введите количество веток на " << i << "точке" << endl;
			int r;
			cin >> r;
			for(int j(0);j<r;j++){
				cout << " введите точку к которой приходит ветка из " << i << " точки на " << j << "ветке" << endl;
				int t; cin >> t; cin.get();
				while (t>size){
					cout << "было введено значение больше чем количество точек" << endl;
					cin >> t;
					cin.get();
				}
				dt[i]->threeds.push_back(dt[t]);
				cout << "укажите массу этой связи" << endl;
				t = 0;
				cin >> t;
				dt[i]->mases.push_back(t);
				
			}
		}
		dt[0]->glob_ms = 0;
	}
private:
	dots *get_min(dots *point) {
		int t=99999999;
		int num(99999999);
		for (int i(0); i < point->mases.size(); i++) {
			if (point->threeds[i]->work == false) {
				if (t > point->mases[i]) {
					t = point->mases[i];
					num = i;

				}
			}
		}
			if (num!= 99999999) {
				point->threeds[num]->work = true;
				return point->threeds[num];
			}
		
		if (t = 99999999) { return nullptr; }

	}
	void obr(dots *wk) {
		for (int i(0); i < wk->threeds.size();i++) {
			if (wk->threeds[i]->glob_ms > wk->glob_ms + wk->mases[i]) {
				wk->threeds[i]->glob_ms = wk->glob_ms + wk->mases[i];
				wk->threeds[i]->parrent = wk;
			}
		}
		wk->work = true;
	}
public:
	~ nood () {
		for (int i(0); i < this->size; i++) {
			delete dt[i];
		}
	}
	void search_qiq_dist() {
		vector<dots*> tmp;
		tmp.push_back(dt[0]);
		for (int i(0); i < this->size; i++) {
			for (int j(0); j < this->dt[i]->threeds.size(); j++) {
				dots *u= get_min(dt[i]);
				if (u!=nullptr) {
					tmp.push_back(u);
				}
			}
		}
		for (int i(0); i < tmp.size(); i++) {
			obr(tmp[i]);
		}
		
		 
			dots *tmp2 = this->dt[size-1];
			while (tmp2->parrent != nullptr) {
				cout << "из " << tmp2->num << " элэметна в " << tmp2->parrent->num << endl;
				tmp2 = tmp2->parrent;
			}
	}
	
};
int main() {
	setlocale(LC_ALL, "Russian");
	nood a;
	a.search_qiq_dist();


	_getch();
	return 0;
}