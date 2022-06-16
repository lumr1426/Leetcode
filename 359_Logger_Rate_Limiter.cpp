#359. Logger Rate Limiter
#Difficulty: Easy
#Design a logger system that receives a stream of messages along with their timestamps. Each unique message should only be printed at most every 10 seconds (i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).

#All messages will come in chronological order. Several messages may arrive at the same timestamp.

#Implement the Logger class:

#Logger() Initializes the logger object.
#bool shouldPrintMessage(int timestamp, string message) Returns true if the message should be printed in the given timestamp, otherwise returns false.

##First Try
class Logger {
public:
    Logger() {
        
    }
    unordered_map<string,int> hash;
    bool shouldPrintMessage(int timestamp, string message) {
        // if ok to print
        if(hash.count(message)==0||(hash.count(message)==1&&hash[message]<=timestamp))
        {
            hash[message]=timestamp+10;
            return true;
        }
        else
            return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

#Time Complexity: O(1)
#Space Complexity: O(n)

#Runtime: 114 ms, faster than 38.32%
#Memory Usage: 32.5 MB, less than 67.04%

#My Comments
#1. Used hash map
#2. if message was first read or was already read and 10seconds have passed, then return true
#3. else return false
#4. using hash, was quite easy to code

#Python3
class Logger:

    def __init__(self):
        self.hash={}
   
    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message not in self.hash or message in self.hash and self.hash[message]<=timestamp:
            self.hash[message]=timestamp+10
            return True
        else: return False


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)

###Python3 for saving memory usage by using two sets
# For detailed explanation: https://leetcode.com/problems/logger-rate-limiter/discuss/365306/Simple-Two-HashMap-Solution-with-O(1)-time-and-little-memory
class Logger:

    def __init__(self):
        self.hashold={}
        self.hashnew={}
        self.init_time=0
   
    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if timestamp>=self.init_time+10:
            self.init_time=timestamp
            self.hashold=self.hashnew
            self.hashnew={}
        if message in self.hashnew:
            return False
        if message in self.hashold and timestamp<self.hashold[message]+10:
            return False
        self.hashnew[message]=timestamp
        return True


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)
