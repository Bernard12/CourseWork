#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n1; //количество вершин в первой доле графа
int n2; //количество вершин во второй доле графа
int m; //количество ребер в графе
vector<int> *adj; //список смежности
vector<bool> used; //массив для хранения информации о пройденных и не пройденных вершинах
int mtSize = 0; //размер максимального паросочетания
vector<int> mt; //массив для хранения ребер, образующих максимальное паросочетание

//алгоритм Куна поиска максимального паросочетания
bool kuhn(int v) {
    //если вершина является пройденной, то не производим из нее вызов процедуры
    if (used[v]) {
        return false;
    }
    used[v] = true; //помечаем вершину первой доли, как пройденную
    //просматриваем все вершины второй доли, смежные с рассматриваемой вершиной первой доли
    for (int i = 0; i < adj[v].size(); ++i) {
        int w = adj[v][i];
    //нашли увеличивающую цепь, добавляем ребро (v, w) в паросочетание
        if (mt[w] == -1 || kuhn(mt[w])) {
            mt[w] = v;
            return true;
    }
    }
    return false;
}

//процедура считывания входных данных с консоли
void readData() {
    //считываем количество вершин в первой и второй доли и количество ребер графа
    printf("Введите количество вершин в первой доли:\n");
    scanf("%d",&n1);
    printf("Введите количество вершин во второй доли:\n");
    scanf("%d",&n2);
    printf("Введите количество ребер:\n");
    scanf("%d",&m);
    //инициализируем список смежности размерности n1
    adj = new vector<int>[n1];
    FILE* f;
    f=fopen("graph1","w");
    fprintf(f, "digraph G\n{\n    node [shape=circle]");
    //считываем граф, заданный списком ребер
    printf("Введите список ребер:\n");
    for (int i = 0; i < m; ++i) {
        int v, w;
        scanf("%d %d", &v, &w);
        fprintf(f,"    %d [color=blue]\n",v );
        fprintf(f,"    %d [color=red]\n",w+n1);
        fprintf(f,"    %d -> %d [dir=none]\n",v,w+n1);
        v--;
        w--;
        //добавляем ребро (v, w) в граф
        adj[v].push_back(w);
    }
    fprintf(f, "}\n");
    fclose(f);
    used.assign(n1, false);
    mt.assign(n2, -1);
}

void solve() {
    //находим максимальное паросочетание
    for (int v = 0; v < n1; ++v) {
    used.assign(n1, false);
    //если нашли увеличивающую цепь,
    //то размер максимального паросочетания увеличиваем на 1
        if (kuhn(v)) {
            mtSize++;
        }
    }
}

void printData() {
    //printf("%d\n", mtSize);
    FILE* f;
    f=fopen("graph2", "w");
    if(f)
    {
        fprintf(f,"digraph G\n{\n node [shape=circle]");
        for (int i = 0; i < n2; ++i) {
            if (mt[i] != -1) {
                fprintf(f,"    %d [color=blue]\n    %d [color=red]\n    %d -> %d [dir=none]\n", mt[i] + 1, i+1+n2, mt[i] + 1, i+1+n2);
            }
        }
        fprintf(f, "}\n");
        fclose(f);
    }
    else printf("Все плохо");
}

int main()
{
    readData();
    solve();
    printData();
    return 0;
}
