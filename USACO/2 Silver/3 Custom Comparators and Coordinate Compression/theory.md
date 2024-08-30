Comparator:

move lower in front of objects of higher value

object x is less than y return true (x < y)
object x is greather or equal than y return false (x <= y, or else)

we can overload the class (struct) operator:
struct Edge {
	int a, b, w;
	bool operator<(const Edge &y) { return w < y.w; }
};

or make a compare function

bool cmp(const Edge &x, const Edge &y) { return x.w < y.w; }
sort(begin(v), end(v), [](const Edge &x, const Edge &y) { return x.w < y.w; });

with two criteria
struct Edge {
	int a, b, w;
	bool operator<(const Edge &y) {
		if (w != y.w) return w < y.w;
		return a < y.a;
	}
};