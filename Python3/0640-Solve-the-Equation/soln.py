class Solution:
    def solveEquation(self, equation):
        """
        :type equation: str
        :rtype: str
        """
        z = eval(equation.replace('x', 'j').replace('=', '-(') + ')', {'j' : 1j})
        constant, coefficient = z.real, -z.imag
        if coefficient != 0:
            return 'x={:d}'.format(int(constant) // int(coefficient))
        else:
            if constant == 0:
                return 'Infinite solutions'
            else:
                return 'No solution'