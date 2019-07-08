class Employee:
    def __init__(self,ID,position,onCall,c):
        self.ID=ID
        self.pos=position # 1 (fresher), 2(TL), 3(PM)
        self.onCall=onCall # 1 or 0
        self.call=c #call
class Call:
    def __init__(self,lvl):
        self.level=lvl
        self.incoming=[] # list of all incoming, undispatched calls
    def incomingCall(self,c):
        self.incoming+=[c]
    def popDispatchCall(self): #Queue
        return self.incoming.pop()
class CallHandler:
    def getCallHandler(self,allcalls,allstaff):
        while not(allcalls):
            if (allcalls[0].lvl==1):
                for i in allstaff:
                    if i.
        
        
        
    
    

        
        