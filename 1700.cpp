class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int unablecount=0;
        while(unablecount!=students.size() || students.size()==0)
        {
             if(students.size()==0 || sandwiches.size()==0)
             {
                return 0;
             }
            
              if(students[0]==sandwiches[0])
              {
                students.erase(students.begin());
                sandwiches.erase(students.begin());
                unablecount=0;
              }
            
            else
            {
                int temp=students.front();
                for(int i=0;i<students.size();i++)
                {
                    students[i]=students[i+1];
                }
                students.back()=temp;
                unablecount++;
            }
        }
        return unablecount;
    }
};
