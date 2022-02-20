class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        square=0
        circle=0
        for i in range(len(students)):
            if students[i]==0:
                square+=1
            else:
                circle+=1
        for i in range(len(sandwiches)):
            if sandwiches[i]==0:
                square-=1
            else:
                circle-=1
            if square<0 or circle<0:
                return len(students)-i
        return 0
            
            
