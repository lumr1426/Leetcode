class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        for i in range(len(image)):
            for j in range(len(image[i])//2):
                temp=image[i][j]
                image[i][j]=image[i][len(image[i])-1-j]
                image[i][len(image[i])-1-j]=temp
        
        for i in range(len(image)):
            for j in range(len(image[i])):
                if image[i][j]:
                    image[i][j]=0
                else:
                    image[i][j]=1
        return image                    
