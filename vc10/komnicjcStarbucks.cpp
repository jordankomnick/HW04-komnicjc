#include "Starbucks.h"
#include "komnicjcStarbucks.h"
#include "Node.h"
#include "Tree.h"

/* member variables and methods declared here */
class komnicjcStarbucks : public Starbucks 
{
public:
	virtual void build(Entry* c, int n);
	virtual Entry* getNearest(double x, double y);
private:
	Node* insert(Entry* e, Node* root);
	Tree* locations;
};

Node* komnicjcStarbucks::insert(Entry* e, Node* root)
{
	if(abs(e -> x - root -> data -> x) <= 0.00001)
	{
		if(abs(e -> y - root -> data -> y) <= 0.00001)
			return NULL;
		else if(e -> y < root -> data -> y)
			root -> left = insert(e, root -> left);
		else
			root -> right = insert(e, root -> right);
	}
	if(e -> x < root -> data -> x)
		root -> left = insert(e, root -> left);
	else
		root -> right = insert(e, root -> right);
	return root;
}

void komnicjcStarbucks::build(Entry* c, int n)
{
	int random = rand() % n;
	locations = new Tree();
	locations -> root = new Node();
	locations -> root -> parent = NULL;
	locations -> root -> left = NULL;
	locations -> root -> right = NULL;
	locations -> root -> data = &c[random];
	for(int i = 0; i < n; i++)
	{
		Node* to_add = new Node();
		to_add -> data = &c[i];
		to_add -> parent = insert(&c[i], locations -> root);
		if(to_add -> data -> x <= to_add -> parent -> data -> x)
			to_add -> parent -> left = to_add;
		else
			to_add -> parent -> right = to_add;
		to_add -> left = NULL;
		to_add -> right = NULL;
	}

}

Entry* komnicjcStarbucks::getNearest(double x, double y)
{
	Entry* temp = new Entry();
	int dist1=-1, dist2=-1, dist3=-1, dist4=-1;
	temp -> x = x;
	temp -> y = y;
	Node* closest_x = insert(temp, locations -> root);
	dist1 = sqrt((closest_x -> data -> x - x)*(closest_x -> data -> x - x) + (closest_x -> data -> y - y)*(closest_x -> data -> y - y));
	if(closest_x -> left != NULL)
		dist2 = sqrt((closest_x -> left -> data -> x - x)*(closest_x -> left -> data -> x - x) + (closest_x -> left -> data -> y - y)*(closest_x -> left -> data -> y - y));
	if(closest_x -> right != NULL)
		dist3 = sqrt((closest_x -> right -> data -> x - x)*(closest_x -> right -> data -> x - x) + (closest_x -> right -> data -> y - y)*(closest_x -> right -> data -> y - y));
	if(closest_x -> parent != NULL)
		dist4 = sqrt((closest_x -> parent -> data -> x - x)*(closest_x -> parent -> data -> x - x) + (closest_x -> parent -> data -> y - y)*(closest_x -> parent -> data -> y - y));
	if(dist1 != -1 && dist1 <= dist2 && dist1 <= dist3 && dist1 <= dist4)
		return closest_x -> data;
	else if(dist2 != -1 && dist2 <= dist1 && dist2 <= dist3 && dist2 <= dist4)
		return closest_x -> left -> data;
	else if(dist3 != -1 && dist3 <= dist1 && dist3 <= dist2 && dist3 <= dist4)
		return closest_x -> right -> data;
	else if(dist4 != -1 && dist4 <= dist1 && dist4 <= dist2 && dist4 <= dist3)
		return closest_x -> parent -> data;
	return NULL;
}
