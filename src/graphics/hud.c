#include "lem_in.h"

bool check_if_click_on_room(t_vector2 mouse_pos)
{
	t_sphere *room;

	room = get_rooms();
	for (int i = 0; i < get_n_rooms(); i++)
	{
		if (mouse_pos.x >= room[i].pos.x - 10 && mouse_pos.x <= room[i].pos.x + 10
			&& mouse_pos.y >= room[i].pos.y - 10 && mouse_pos.y <= room[i].pos.y + 10)
			return (true);
	}
	return (false);
}