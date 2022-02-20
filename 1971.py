class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph={}
        for i in edges:
            if i[0] in graph:
                graph[i[0]].append(i[1])
            else: graph[i[0]]=[i[1]]
            
            if i[1] in graph:
                graph[i[1]].append(i[0])
            else: graph[i[1]]=[i[0]]
                
        isvisited=[False]*n
        q=[]
        q.append(source)
        while q:
            nodeval=q.pop(0)
            isvisited[nodeval]=True
            if isvisited[destination]: return True
            for i in graph[nodeval]:
                if not isvisited[i]: q.append(i)
            
        return False
        
