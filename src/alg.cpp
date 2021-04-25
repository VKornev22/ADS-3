// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int priority(char priority){
  switch (priority) {
    case '(':
        return 0;
        break;
    case ')':
        return 1;
        break;
    case '+':
        return 2;
        break;
    case '-':
        return 2;
        break;
    case '*':
        return 3;
        break;
    case '/':
        return 3;
        break;
    default:
        return -1;
    }
}
int calculate(int first, int second, char oper){
  switch (priority) {
    case '+':
        return first + second;
        break;
    case '-':
        return first - second;
        break;
    case '*':
      return first * second;
      break;
    case '/':
        return first / second;
        break;
    default:
        return -1;
    }
}



std::string infx2pstfx(std::string inf) {
        TStack<char> stack;
        std::string result;
        for (int i = 0; i < inf.length(); ++i) {
                if (isdigit(inf[i]) ) {
                        while (isdigit(inf[i])) {
                                result += inf[i];
                                i++;
                        }
                        i--;
                        result += ' ';
                }
        }
        else if ((inf[i] == '(') || (stack.isEmpty()) || (priority(inf[i]) > priority(stack.get()))) {
                stack.push(inf[i]);
        }
        else if (inf[i] == ')') {
                char l = stack.get();
                stack.pop();
        while (l!= '(') {
                result += l;
                result = ' ';
                l = stack.get();
                stack.pop();
        }
        }
        else {
                while (!stack.isEmpty() && (priority(stack.get()) >= priority(inf[i]))) {
        result += stack.get();
        result += ' ';
        stack.pop();
        }
        stack.push(inf[i]);
        }
        }
                while (!stack.isEmpty()) {
                result += stack.get();
                result += ' ';
                stack.pop();
        }
        result.pop_back();
        return result;
        }
}

int eval(std::string pst) {
  TStack <int> pstStack;
  for (int i = 0; i < pst.size(); i++)
  {
    char ch = pst[i];
    int pri = priority(ch);
    if (pri == -1)
      pstStack.push(ch - 48);
    else
    {
      int num1 = pstStack.get();
      pstStack.pop();
      int num2 = pstStack.get();
      pstStack.pop();
      int res = calculate(num1, num2, ch);
      pstStack.push(res);
    } 
  }
  return pstStack.get();
}
