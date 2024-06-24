
class Tower
{
public:
    Tower(int x, int y, int health, int dmg, int tear, int cost)
    {
        this->x = x;
        this->y = y;
        this->health = health;
        this->dmg = dmg;
        this->tear = tear;
        this->cost = cost;
    }
    ~Tower();

    
private:
    int x;
    int y;
    int health;
    int dmg;
    int tear;
    int cost;

};
