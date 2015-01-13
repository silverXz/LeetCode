const int INTMAX = ~(1 << (sizeof(int) * 8 - 1));

class MinStack {
private:
    stack<int> mStack;
    stack<int> mMinStack;
    int minimum;
public:
    MinStack()
    {
        minimum = INT_MIN;
    }

    void push(int x) {
        mStack.push(x);
        if( mMinStack.empty() || x <= minimum )
        {
            minimum = x;
            mMinStack.push(minimum);
        }
    }

    void pop() {
        if( mStack.empty() )
            return;
        int top = mStack.top();
        mStack.pop();
        if( top == mMinStack.top())
            mMinStack.pop();
        if( !mMinStack.empty())
            minimum = mMinStack.top();
    }

    int top() {
        return mStack.top();
    }

    int getMin() {
        return minimum;
    }
};
