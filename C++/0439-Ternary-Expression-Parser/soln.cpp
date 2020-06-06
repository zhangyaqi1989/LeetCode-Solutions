class Solution {
public:
    string parseTernary(string expression) {
        while (true) {
            int idx = expression.rfind('?');
            if (idx == string::npos) return expression;
            else {
                char TF = expression[idx - 1];
                char result = (TF == 'T' ? expression[idx + 1] : expression[idx + 3]);
                expression = expression.substr(0, idx - 1) + result + expression.substr(idx + 4);
            }
        }
    }
};
