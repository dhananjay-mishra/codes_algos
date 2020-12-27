 int n = x.size();
    
    stack<char> s;
    
    for(int i = 0 ; i < n; i++){
        if(x[i] == '(' || x[i] == '{' || x[i] == '[')
        s.push(x[i]);
        else
        if(!s.empty()){
        if(x[i] == ')' && s.top() != '(')
            return false;
        
        if(x[i] == ']' && s.top() != '[')
            return false;
        
        if(x[i] == '}' && s.top() != '{')
           return false;
        
             s.pop();
            
        }
       else
       return false;
    }

        if(s.size()!=0)
        return false;
        
        return true;