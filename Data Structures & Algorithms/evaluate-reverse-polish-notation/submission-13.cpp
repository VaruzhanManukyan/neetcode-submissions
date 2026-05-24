class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> st;
        st.reserve(tokens.size());

        for (const auto& token : tokens) {
            if (token.size() == 1) {
                char c = token[0];

                if (c == '+' || c == '-' || c == '*' || c == '/') {
                    int b = st.back();
                    st.pop_back();

                    int a = st.back();
                    st.pop_back();

                    switch (c) {
                        case '+': st.push_back(a + b); break;
                        case '-': st.push_back(a - b); break;
                        case '*': st.push_back(a * b); break;
                        case '/': st.push_back(a / b); break;
                    }

                    continue;
                }
            }

            st.push_back(std::stoi(token));
        }

        return st.back();
    }
};