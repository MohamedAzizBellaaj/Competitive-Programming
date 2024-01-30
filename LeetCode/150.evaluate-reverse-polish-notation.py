#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#


# @lc code=start
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        def evaluate(op1, op2, operator):
            match operator:
                case "+":
                    return op1 + op2

                case "-":
                    return op1 - op2

                case "*":
                    return op1 * op2

                case "/":
                    return int(op1 / op2)

        stack = []

        for token in tokens:
            if token in "+-*/":
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(evaluate(op1, op2, token))

            else:
                stack.append(int(token))

        return stack.pop()


# @lc code=end
