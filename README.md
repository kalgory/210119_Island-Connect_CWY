# 210119_Island-Connect_CWY

최단경로를 찾는 문제



프림 알고리즘 vs 크루스칼 알고리즘

n: 노드의 개수

p: edge의 개수



일반적으로 프림은 O(n^2), 크루스칼은 O(plogp)의 시간복잡도를 가진다. 이 문제에서는 p의 개수가 n(n-1)/2로 제한되어 있기때문에 크루스칼로 구현함.

# Flowchart

![island connect](\island connect.jpg)