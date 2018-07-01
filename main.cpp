#include <QCoreApplication>
#include <iostream>
#include <set>
#include <vector>
#include <QElapsedTimer>
#include <chrono>
#include <QDebug>

int N;

using namespace std;

void search(vector<vector<int> > state,set<int> columns,const int &d) {
    if (d == N) {

/*        for (auto i:state) {
            for (auto j:i)
                cout << (j == 0 || j==1 ?'-' : '+') ;
            cout << endl;
        }
        cout <<endl<< string(N,'#') << endl;
  */
        return;
    }
    for (auto it = columns.begin(); it != columns.end(); ++it)
    {

        if (state[d][*it]==0) {
            auto tmpState = state;
            tmpState[d][*it] = 2;
            auto tmpColumns = columns;
            for (int i = d+1; i < N; i++)
                tmpState[i][*it] = 1;
            for (int i = 1;d+i < N && *it+i <N ; i++)
                tmpState[d+i][*it+i]=1;
            for (int i = 1;d+i < N && *it-i >=0 ; i++)
                tmpState[d+i][*it-i]=1;
            tmpColumns.erase(*it);
            search(tmpState,tmpColumns,d+1);
        }

    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    using namespace std::chrono;
    cin >> N;
    vector <vector <int> > map(N,vector<int>(N,0));

    set<int> column;
    for (int i=0;i<N;i++)
        column.insert(i);
    QElapsedTimer timer;
    timer.start();
    search(map, column, 0);
    qDebug() << timer.elapsed();

    return a.exec();
}
