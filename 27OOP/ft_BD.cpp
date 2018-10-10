#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class	c_gamefield
{
private:
	int		x;
	int		y;
	int		obs;
	char		**field;
	friend ostream	&operator<<(ostream &os, const c_gamefield &obj);
public:

	c_gamefield();
	c_gamefield(int X, int Y, int OBS);
	c_gamefield(c_gamefield &obj);

	void	ft_setx(int X)
	{
		x = X;
	}

	void	ft_sety(int Y)
	{
		y = Y;
	}

	void	ft_setobs(int OBS)
	{
		obs = OBS;
	}
	
	void	ft_set_f()
	{
		field = ft_gen_field();
	}

	int	ft_getx()
	{
		return (x);
	}

	int	ft_gety()
	{
		return (y);
	}
	
	int	ft_getobs()
	{
		return (obs);
	}

	char	**ft_get_f()
	{
		return (field);
	}

	char	**ft_gen_field()
	{
		srand(time ( NULL ));

		char	**field_d  = new char* [ft_gety()];
		int	i;
		int	j;

		;
		j = 0;
		while (j < ft_gety())
		{
			i = 0;
			field_d[j] = new char [ft_getx()];
			while (i < ft_getx())
			{
				(rand() % obs) ? field_d[j][i] = '.': field_d[j][i]  = 'o';
				i++;
			}
			j++;
		}
		return (field_d);
	}

	void	ft_field_out()
	{
		char	**field_BUF = ft_get_f();
		for (int i = 0;  i < ft_gety(); i++)
		{
			for(int j = 0; j < ft_getx(); j++)
			{
				cout << field_BUF[i][j];
			}
			cout << endl;
		}
	}

	~c_gamefield();
};

c_gamefield :: c_gamefield(int X, int Y, int OBS)
{
	x = X;
	y = Y;
	obs = OBS;
}

c_gamefield :: c_gamefield()
{
	x = 1;
	y = 1;
	obs = 1;
}

c_gamefield :: c_gamefield(c_gamefield &obj)
{	
	x = obj.ft_getx();
	y = obj.ft_gety();
}


ostream		&operator<<(ostream &os, const c_gamefield &obj)
{
	os << obj.x << endl << obj.y << endl;
	return (os);
}

c_gamefield :: ~c_gamefield()
{
}

int	main(void)
{
	int a = 6;
	int b = 6;
	int c = 10;
	c_gamefield city {6, 6, 10};
	cout << city;
	c_gamefield city1 = city;
	cout << city1;
	city.ft_set_f();
	city.ft_field_out();
	city.ft_setx(10);
	city.ft_sety(10);
	city.ft_setobs(20);
	city.ft_set_f();
	city.ft_field_out();
	
	return (0);
}
