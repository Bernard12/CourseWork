import networkx as nx
import matplotlib.pyplot as plt
import numpy,random
import tkinter as tk
from PIL import Image
def input_adjen():
    n=int(input())
    arr=[]
    for i in range(n):
        arr.append([])
    for i in range(n):
        cur=input().replace(',','')
        cur=cur.replace('  ','')
        li=cur.split(" ")
        for j in range(len(li)):
            try:
                arr[i].append(int(li[j]))
            except ValueError:
                print("Its not a number")
    return arr

def build_new_graph(tuples,number_of_edges):
    res=[]
    for i in range(number_of_edges):
        res.append([])
        for j in range(number_of_edges):
            res[i].append(0)
    for i in range(len(tuples)):
        x=tuples[i][0]
        y=tuples[i][1]
        for j in range(len(tuples)):
            if i==j :
                continue
            else:
                x_j=tuples[j][0]
                y_j=tuples[j][1]
                flag1= x==x_j or x==y_j
                flag2= y==x_j or y==y_j
                if flag1 or flag2:
                    res[i][j]=1
    return res

def parse_colors(dict,edges):
    res=[]
    temp={}
    for i in dict:
        ed=i
        color=dict[ed]
        if not color in temp:
            temp[color]=[ed]
        else:
            temp[color].append(ed)
    for i in temp:
        res.append(temp[i])
    temp=[]
    for i in range(len(res)):
        temp.append([])
        for j in range(len(res[i])):
            temp[i].append(edges[res[i][j]])
    return temp

matrix=input_adjen()
print(matrix)
Temp=numpy.matrix(matrix)
graph=nx.from_numpy_matrix(Temp)
print(graph.nodes())
print(graph.number_of_edges())
li=graph.edges()
print(li)

new_graph=nx.from_numpy_matrix(numpy.matrix(build_new_graph(li,graph.number_of_edges())))

print(numpy.matrix(build_new_graph(li,graph.number_of_edges())))

test=nx.coloring.greedy_color(new_graph,strategy=nx.coloring.strategy_largest_first)

pos=nx.circular_layout(graph)
print(test)
ans=parse_colors(test,li)
print(ans)
hromo_num=len(ans)


frame=tk.Frame()
frame.pack()



tk.Label(frame,text='Hromo num').pack(side=tk.TOP) # ширина-высота


labels_of_nodes={}
for i in range(0,graph.number_of_nodes()):
    labels_of_nodes[i]=(str(i+1))
print(labels_of_nodes)
nx.draw_networkx_nodes(graph,pos,node_list=[0,1,2,3],node_color='g',node_size=500)
nx.draw_networkx_labels(graph,pos,labels_of_nodes,font_size=15)

print(hromo_num)


for i in range(len(ans)):
    color='#{:06x}'.format(random.randint(0, 0xffff00))
    nx.draw_networkx_edges(graph,pos,edgelist=ans[i],edge_color=color,edge_size=100,width=17)


plt.axis('off')
plt.savefig('test.png')
#plt.show()

image=tk.PhotoImage(file='./test.png')
tk.Label(frame,image=image).pack(side=tk.BOTTOM)

frame.mainloop()
