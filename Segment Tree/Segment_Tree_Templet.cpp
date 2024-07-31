#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int v = 0; // We can use more variables depending on what all info we need !
	// 1. this is identitiyElement - default node value which will not impact answer on taken
	Node() {}
	Node(int val)
	{
		v = val; // 2. Node constructor will change depending on, what we need to initialize
	}

	void merge(const Node &l, const Node &r)
	{				   // v is each nodes data, while l & r are children
		v = l.v + r.v; // 3. Merge function (merge logic can change)
	}
};

class Update
{
public:
	int v = 0;
	// 4. this is identity Transformation - default update value assigned before or after the operation
	Update(){};
	Update(int val)
	{
		v = val; // 5. Update constructor initialization
	}

	void combine(const Update &otherUpdate, const int &tl, const int &tr)
	{						// combing the update, to give to chidren in future
		v = otherUpdate.v; // 6. OtherUpdate is the newest update ['=' or '+=' depends on 'assign/set' vs 'add']
	}

	void apply(Node &node, const int &tl, const int &tr) const
	{
		node.v = (tr - tl + 1) * v; // 7. applying the update received on the node
	}
};

template <typename node, typename update>
class SegTree
{
public:
	int len;
	// t is the segment Tree
	vector<node> t;
	vector<update> unpropUpd; // the actual val of un-propogated updates to be processed
	vector<bool> isLazy;	  // tells if a certain node is storing un-propogated updates or not
	node identityElement;
	update identityTransformation;

	SegTree() {}
	SegTree(int l)
	{
		len = l;
		t.resize(4 * len);
		isLazy.resize(4 * len);
		unpropUpd.resize(4 * len);
		identityElement = node();
		identityTransformation = update();
	}

	// asking v, to remember that he has 'val' update for his range
	void apply(const int &v, const int &tl, const int &tr, const update &upd)
	{ // [tl, tr] is node range
		if (tl != tr)
		{ // leaf nodes can't be lazy, as they have no-one to propogate to
			isLazy[v] = true;
			unpropUpd[v].combine(upd, tl, tr); // stacking up the unpropogaed value, which i'll propogate down
		}
		upd.apply(t[v], tl, tr); // this "= shows assign update", "+= shows range add update"
	}

	// assigning the value whatsoever we had on 'v' to its children ('2*v' & '2*v+1')
	void pushDown(const int &v, const int &tl, const int &tr)
	{
		if (!isLazy[v])
			return;		   // if not lazy then no push-down required
		isLazy[v] = false; // no more lazy
		int tm = (tl + tr) / 2;
		apply(2 * v, tl, tm, unpropUpd[v]);			// propogates to left child
		apply(2 * v + 1, tm + 1, tr, unpropUpd[v]); // propogates to right child
		unpropUpd[v] = identityTransformation;		// identity-transformation -- updated the children(job done)
	}

	// Build Segment Tree -- build(a, 1, 0, len-1);
	template <typename T>
	void build(const T &a, const int &v, const int &tl, const int &tr)
	{
		if (tl == tr)
		{
			t[v] = a[tl];
			return;
		}
		int tm = (tl + tr) / 2;
		build(a, 2 * v, tl, tm);
		build(a, 2 * v + 1, tm + 1, tr);
		t[v].merge(t[2 * v], t[2 * v + 1]);
	}

	// Query input question is = [l, r] included -- query(1, 0, len-1, l, r)
	node query(const int &v, const int &tl, const int &tr, const int &l, const int &r)
	{
		if (tl > r || tr < l)
			return identityElement; // no overlap
		if (l <= tl && tr <= r)
			return t[v]; // Full overlap

		// Partial Overlap
		pushDown(v, tl, tr); // we remove the lazy tag before going down, so children have correct info
		int tm = (tl + tr) / 2;
		node leftAns = query(2 * v, tl, tm, l, r);
		node rightAns = query(2 * v + 1, tm + 1, tr, l, r);
		node ans;
		ans.merge(leftAns, rightAns);
		return ans;
	}

	// Update at index id of nums to a value val (assign/override/set) -- update(1, 0, len-1, l, r, val)
	void rangeUpdate(const int &v, const int &tl, const int &tr, const int &l, const int &r, const update &upd)
	{
		// reached leaf node
		if (l <= tl && tr <= r)
		{ // full overlap -- apply update and return back
			apply(v, tl, tr, upd);
			return;
		}
		if (tl > r || tr < l)
			return; // no overlap

		// Partial Overlap
		pushDown(v, tl, tr);
		int tm = (tl + tr) / 2;
		rangeUpdate(2 * v, tl, tm, l, r, upd);
		rangeUpdate(2 * v + 1, tm + 1, tr, l, r, upd);
		t[v].merge(t[2 * v], t[2 * v + 1]);
	}

	// over-ridden functions
	template <typename T>
	void build(const T &a)
	{
		build(a, 1, 0, len - 1);
	}

	node query(const int &l, const int &r)
	{
		return query(1, 0, len - 1, l, r);
	}

	void rangeUpdate(const int &l, const int &r, const update &upd)
	{
		rangeUpdate(1, 0, len - 1, l, r, upd);
	}
};



int main()
{
	int n, q;
	cin >> n >> q;
	SegTree<Node, Update> segTree(n);
	vector<int> a(n+1, 0);

	segTree.build(a);

	while(q--){
		int l, r, c;
		cin >> l >> r >> c;

		segTree.rangeUpdate(l, r, c);
	}

	for (int i = 1; i <= n; i++){
		cout << segTree.query(i, i).v << endl;
	}

	// int n = 8;
	// vector<int> a = {1, 2, 1, 4, 2, 3, 1, 1};

	// SegTree<Node, Update> segTree(n);
	// segTree.build(a);

	// // Build - View Build Data
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << segTree.query(i, i).v << " ";
	// }
	// cout << endl;

	// // Query - Range Query
	// int sum = segTree.query(1, 5).v;
	// cout << "Sum for range id = 1 to id = 5 is: " << sum << endl;

	// // Update - Point Update
	// segTree.rangeUpdate(2, 2, 10); // at id=2 [i.e. l=2, r=2],make the value = 10
	// sum = segTree.query(1, 5).v;
	// cout << "New Sum for range id = 1 to id = 5 is: " << sum << endl;

	// for (int i = 0; i < n; i++)
	// {
	// 	cout << segTree.query(i, i).v << " ";
	// }
	// cout << endl
	// 	 << endl;

	// segTree.rangeUpdate(2, 7, 10);
	// segTree.rangeUpdate(2, 7, 20);
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << segTree.query(i, i).v << " ";
	// }
	// cout << endl;

	// sum = segTree.query(2, 3).v;
	// cout << "New Sum for range l = 2 to r = 3 is: " << sum << endl;
}


// ********************* NOT A GENERIC CODE ********************

// class SegTree
// {
// public:
// 	int len;
// 	// t is the segment Tree
// 	vector<int> t, unpropUpd; // the actual val of un-propogated updates to be processed
// 	vector<bool> isLazy;	  // tells if a certain node is storing un-propogated updates or not

// 	SegTree() {}
// 	SegTree(int l)
// 	{
// 		len = l;
// 		t.resize(4 * len);
// 		isLazy.resize(4 * len);
// 		unpropUpd.resize(4 * len);
// 	}

// 	// asking v, to remember that he has 'val' update for his range
// 	void apply(int v, int tl, int tr, int val)
// 	{ // [tl, tr] is node range
// 		if (tl != tr)
// 		{ // leaf nodes can't be lazy, as they have no-one to propogate to
// 			isLazy[v] = true;
// 			unpropUpd[v] = val; // stacking up the unpropogaed value, which i'll propogate down
// 		}
// 		t[v] = (tr - tl + 1) * val; // this "= shows assign update", "+= shows range add update"
// 	}

// 	// assigning the value whatsoever we had on 'v' to its children ('2*v' & '2*v+1')
// 	void pushDown(int v, int tl, int tr)
// 	{
// 		if (!isLazy[v])
// 			return;		   // if not lazy then no push-down required
// 		isLazy[v] = false; // no more lazy
// 		int tm = (tl + tr) / 2;
// 		apply(2 * v, tl, tm, unpropUpd[v]);			// propogates to left child
// 		apply(2 * v + 1, tm + 1, tr, unpropUpd[v]); // propogates to right child
// 		unpropUpd[v] = 0;							// identity-transformation -- updated the children(job done)
// 	}

// 	// Build Segment Tree -- build(a, 1, 0, len-1);
// 	void build(vector<int> &a, int v, int tl, int tr)
// 	{
// 		if (tl == tr)
// 		{
// 			t[v] = a[tl];
// 			return;
// 		}
// 		int tm = (tl + tr) / 2;
// 		build(a, 2 * v, tl, tm);
// 		build(a, 2 * v + 1, tm + 1, tr);
// 		t[v] = t[2 * v] + t[2 * v + 1];
// 	}

// 	// Query input question is = [l, r] included -- query(1, 0, len-1, l, r)
// 	int query(int v, int tl, int tr, int l, int r)
// 	{
// 		if (tl > r || tr < l)
// 			return 0; // no overlap
// 		if (l <= tl && tr <= r)
// 			return t[v]; // Full overlap

// 		// Partial Overlap
// 		pushDown(v, tl, tr); // we remove the lazy tag before going down, so children have correct info
// 		int tm = (tl + tr) / 2;
// 		int leftAns = query(2 * v, tl, tm, l, r);
// 		int rightAns = query(2 * v + 1, tm + 1, tr, l, r);
// 		return leftAns + rightAns;
// 	}

// 	// Update at index id of nums to a value val (assign/override/set) -- update(1, 0, len-1, l, r, val)
// 	void update(int v, int tl, int tr, int l, int r, int val)
// 	{
// 		// reached leaf node
// 		if (l <= tl && tr <= r)
// 		{ // full overlap -- apply update and return back
// 			apply(v, tl, tr, val);
// 			return;
// 		}
// 		if (tl > r || tr < l)
// 			return; // no overlap

// 		// Partial Overlap
// 		pushDown(v, tl, tr);
// 		int tm = (tl + tr) / 2;
// 		update(2 * v, tl, tm, l, r, val);
// 		update(2 * v + 1, tm + 1, tr, l, r, val);
// 		t[v] = t[2 * v] + t[2 * v + 1];
// 	}

// 	// over-ridden functions
// 	void build(vector<int> &a)
// 	{
// 		build(a, 1, 0, len - 1);
// 	}

// 	int query(int l, int r)
// 	{
// 		return query(1, 0, len - 1, l, r);
// 	}

// 	void update(int l, int r, int val)
// 	{
// 		update(1, 0, len - 1, l, r, val);
// 	}
// };

// int main()
// {
// 	// Shortcut to run the program is Ctrl + Shift + B
// 	// Shortcut to run using separate test is Ctrl + Alt + B

// 	int n = 8;
// 	vector<int> a = {1, 2, 1, 4, 2, 3, 1, 1};

// 	SegTree segTree(n);
// 	segTree.build(a); 

// 	// Build - View Build Data
// 	for (int i = 0; i < n; i++)
// 	{
// 		cout << segTree.query(i, i) << " ";
// 	}
// 	cout << endl;

// 	// Query - Range Query
// 	int sum = segTree.query(1, 5);
// 	cout << "Sum for range id = 1 to id = 5 is: " << sum << endl;

// 	// Update - Point Update
// 	segTree.update(2, 2, 10); // at id=2 [i.e. l=2, r=2],make the value = 10
// 	sum = segTree.query(1, 5);
// 	cout << "New Sum for range id = 1 to id = 5 is: " << sum << endl;

// 	for (int i = 0; i < n; i++)
// 	{
// 		cout << segTree.query(i, i) << " ";
// 	}
// 	cout << endl
// 		 << endl;

// 	segTree.update(2, 7, 10);
// 	segTree.update(2, 7, 20);
// 	for (int i = 0; i < n; i++)
// 	{
// 		cout << segTree.query(i, i) << " ";
// 	}
// 	cout << endl;

// 	sum = segTree.query(2, 3);
// 	cout << "New Sum for range l = 2 to r = 3 is: " << sum << endl;
// }










// peak index

// bool isPeak(int i, vector<int> &nums)
// {
// 	return ((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]));
// }

// vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>> &queries)
// {
// 	int n = nums.size();
// 	SegTree<Node, Update> segTree(n);

// 	vector<Node> initialData(n);

// 	for (int i = 1; i <= n - 2; i++)
// 	{
// 		if (isPeak(i, nums))
// 		{
// 			initialData[i] = Node(1);
// 		}
// 	}

// 	segTree.build(initialData);

// 	vector<int> ans;

// 	for (int i = 0; i < queries.size(); i++)
// 	{
// 		if (queries[i][0] == 1)
// 		{
// 			int l = queries[i][1];
// 			int r = queries[i][2];

// 			if (l + 1 <= r - 1)
// 			{
// 				ans.push_back(segTree.query(l + 1, r - 1).v);
// 			}
// 			else
// 			{
// 				ans.push_back(0);
// 			}
// 		}
// 		else
// 		{
// 			int ind = queries[i][1];
// 			int val = queries[i][2];
// 			nums[ind] = val;

// 			int next = ind + 1;
// 			int prev = ind - 1;

// 			if (prev >= 1)
// 			{
// 				if (isPeak(prev, nums))
// 				{
// 					segTree.rangeUpdate(prev, prev, Update(1));
// 				}
// 				else
// 				{
// 					segTree.rangeUpdate(prev, prev, Update(0));
// 				}
// 			}

// 			if (next <= n - 2)
// 			{
// 				if (isPeak(next, nums))
// 				{
// 					segTree.rangeUpdate(next, next, Update(1));
// 				}
// 				else
// 				{
// 					segTree.rangeUpdate(next, next, Update(0));
// 				}
// 			}

// 			if (ind >= 1 && ind <= n - 2)
// 			{
// 				if (isPeak(ind, nums))
// 				{
// 					segTree.rangeUpdate(ind, ind, Update(1));
// 				}
// 				else
// 				{
// 					segTree.rangeUpdate(ind, ind, Update(0));
// 				}
// 			}
// 		}
// 	}

// 	return ans;
// }