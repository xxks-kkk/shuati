# Evaluate the value of an arithmetic expression in Reverse Polish Notation.
#
# Valid operators are +, -, *, /. Each operand may be an integer or another expression.
#
# Some examples:
#   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
#   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        operators = {"+", "-", "*", "/"}
        stack = []
        for token in tokens:
            if token not in operators:
                stack.append(token)
            else:
                operand1 = int(stack.pop())
                operand2 = int(stack.pop())
                if token == "+":
                    stack.append(operand2 + operand1)
                elif token == "-":
                    stack.append(operand2 - operand1)
                elif token == "*":
                    stack.append(operand2 * operand1)
                elif token == "/":
                    stack.append(operand2 / float(operand1))
        return int(stack.pop())

if __name__ == "__main__":
    sol = Solution()
    assert sol.evalRPN(["2", "1", "+", "3", "*"]) == 9
    assert sol.evalRPN(["4", "13", "5", "/", "+"]) == 6
    assert sol.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]) == 22