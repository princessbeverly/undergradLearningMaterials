const minimum_grid_width = 8;
const maximum_grid_width = 40;
const all_colors = [
	'var(--pretty_indigo)',
	'var(--pretty_red)',
	'var(--pretty_yellow)',
	'var(--pretty_green)',
	'var(--pretty_light)',
	'var(--pretty_dark)'
];

let hard_coded_difficulty = 6;
let grid_width = 8;
let grid_cell_count = grid_width * grid_width;
let color_count = 3;
let cells;
let visited_cells;
let neighbor_cells;
let move_count;
let move_limit;




//// FUNCTIONS

/* Initializes all the variables for the game. */
const initialize_game = () => {
	cells = new Array();
	visited_cells = new Set([0]);
	neighbor_cells = new Set([1]);
	move_count = 0;
	move_limit = Math.floor(color_count * 2 * grid_width / hard_coded_difficulty);

	/* Initializing the cells' color codes. */
	for (let i = 0; i < grid_cell_count; i ++)
	{
		cells.push(Math.floor(Math.random() * color_count));
	}

	display_grid();
	update_neighbors();

	/* Displaying game information. */
	document.getElementById('dimensions').innerHTML = 'Dimensions<br>' + grid_width.toString() + ' x ' + grid_width.toString();
	document.getElementById('moves').innerHTML = 'Moves<br>' + move_count.toString() + ' / ' + move_limit.toString();
	document.getElementById('colors').innerHTML = 'Colors<br>' + color_count.toString();

	console.log('CELLS: ', cells);
	console.log('VISITED: ', visited_cells);
	console.log('NEIGHBORS: ', neighbor_cells);
}

/* Displays the tiles within the grid. */
const display_grid = () => {
	let tile_width = 'calc(56vh / ' + grid_width.toString() + ')';

	/* Emptying the game grid. */
	document.getElementById('game_grid').innerHTML = '<span></span>';

	/* Iterating over all the cells. */
	for (let i = 0; i < grid_cell_count; i ++)
	{
		/* Creating a new empty span. */
		new_span = document.createElement('span');
		new_span.style.backgroundColor = all_colors[cells[i]];
		new_span.style.display = 'inline-block';
		new_span.style.height = tile_width;
		new_span.style.width = tile_width;
		new_span.id = 't' + i.toString();
		new_span.className = 'tile';

		/* Adding the span to game_grid. */
		document.getElementById('game_grid').append(new_span);

		/* Moving the spans to a new line. */
		if ((i % grid_width) == (grid_width - 1))
		{
			document.getElementById('game_grid').innerHTML += '<br>';
		}
	}

	/* Guaranteeing uniqueness of the first cell. */
	let first_span = document.getElementById('t0');
	let color_index = 0;

	while (color_index == cells[1] || color_index == cells[grid_width])
	{
		color_index ++;
	}

	first_span.style.backgroundColor = all_colors[color_index];
	cells[0] = color_index;
};

/* Finds indirect neighbors of the visited cells of the same color_index. */
const find_related_neighbors = (current_cell) => {
	/* Setting temporary cells. */
	let left_cell = current_cell - 1;
	let right_cell = current_cell + 1;
	let up_cell = current_cell - grid_width;
	let down_cell = current_cell + grid_width;

	/* Adding the current cell. */
	neighbor_cells.add(current_cell);

	/* Checking and adding the cell above. */
	if (
		(up_cell >= 0) &&
		!visited_cells.has(up_cell) &&
		!neighbor_cells.has(up_cell) &&
		cells[current_cell] == cells[up_cell]
	)
	{
		find_related_neighbors(up_cell);
	}

	/* Checking and adding the cell below. */
	if (
		(down_cell < grid_cell_count) &&
		!visited_cells.has(down_cell) &&
		!neighbor_cells.has(down_cell) &&
		cells[current_cell] == cells[down_cell]
	)
	{
		find_related_neighbors(down_cell);
	}

	/* Checking and adding the cell on the left. */
	if (
		(current_cell % grid_width != 0) &&
		!visited_cells.has(left_cell) &&
		!neighbor_cells.has(left_cell) &&
		cells[current_cell] == cells[left_cell]
	)
	{
		find_related_neighbors(left_cell);
	}

	/* Checking and adding the cell on the right. */
	if (
		((current_cell % grid_width) != (grid_width - 1)) &&
		!visited_cells.has(right_cell) &&
		!neighbor_cells.has(right_cell) &&
		cells[current_cell] == cells[right_cell]
	)
	{
		find_related_neighbors(right_cell);
	}
};

/* Updating the clickable neighbor cells. */
const update_neighbors = () => {
	/* Clearing all the neighboring cells and their styles. */
	neighbor_cells = new Set();

	/* Adding a white border for debugging purposes. */
	// neighbor_cells.forEach((index) => {
	// 	document.getElementById('t' + index.toString()).style.border = 'none';
	// });

	/* Iterating over all the visited cells. */
	visited_cells.forEach((current_cell) => {
		/* Setting temporary cells. */
		let left_cell = current_cell - 1;
		let right_cell = current_cell + 1;
		let up_cell = current_cell - grid_width;
		let down_cell = current_cell + grid_width;

		/* Checking and adding the cell above. */
		if (
			(up_cell >= 0) &&
			!(visited_cells.has(up_cell))
		)
		{
			neighbor_cells.add(up_cell);
		}

		/* Checking and adding the cell below. */
		if (
			(down_cell < grid_cell_count) &&
			!(visited_cells.has(down_cell))
		)
		{
			neighbor_cells.add(down_cell);
		}

		/* Checking and adding the cell on the left. */
		if (
			(current_cell % grid_width != 0) &&
			!(visited_cells.has(left_cell))
		)
		{
			neighbor_cells.add(left_cell);
		}

		/* Checking and adding the cell on the right. */
		if (
			((current_cell % grid_width) != (grid_width - 1)) &&
			!(visited_cells.has(right_cell))
		)
		{
			neighbor_cells.add(right_cell);
		}
	});

	/* Updating related neighbors recursively. */
	neighbor_cells.forEach((index) => {
		find_related_neighbors(index);
	});

	/* Highlighting cells for debugging purposes. */
	// neighbor_cells.forEach((index) => {
	// 	document.getElementById('t' + index.toString()).style.border = '2px solid white';
	// });
};

/* Updating the colors of visited cells. */
const update_colors = (color_index, new_color) => {
	/* Iterating over the visited cells. */
	visited_cells.forEach((current_cell) => {
		let current_span = document.getElementById('t' + current_cell.toString());

		/* Updatings the cells and the spans. */
		cells[current_cell] = color_index;
		current_span.style.backgroundColor = new_color;
	});
};

/* Adds all the neighbors with the same color. */
const add_same_neighbors = (tile_index, color_index) => {
	visited_cells.add(tile_index);

	neighbor_cells.forEach((index) => {
		if (cells[index] == color_index)
		{
			visited_cells.add(index);
		}
	});
}

/* Processes the user's mouse click. */
const process_tile = (clicked_element, tile_index) => {
	// console.log('TILE CLICKED: ' + tile_index.toString());

	/* Making sure a neighbor tile is clicked. */
	if (!neighbor_cells.has(tile_index))
	{
		console.log('>> non-neighbor selected');
		return;
	}

	console.log('>> neighbor selected');

	/* Adding the current tile and updating colors to match. */
	add_same_neighbors(tile_index, cells[tile_index]);
	update_neighbors();
	update_colors(cells[tile_index], all_colors[cells[tile_index]]);

	/* Updating the move count. */
	move_count ++;
	document.getElementById('moves').innerHTML = 'MOVES<br>' + move_count.toString() + ' / ' + move_limit.toString();

	/* Checking the win condition. */
	if (
		(move_count <= move_limit) &&
		(visited_cells.size == grid_cell_count)
	)
	{
		document.getElementById('game_grid').innerHTML = '<p class="glow">Congratulations! You beat the game!</p>';
	} else if  (
		(move_count >= move_limit) &&
		(visited_cells.size != grid_cell_count)
	)
	{
		document.getElementById('game_grid').innerHTML = '<p class="glow">Oh no! It seems you ran out of moves!</p>';
	}
};

/* Adjusts the grid size. */
document.getElementById('grid_up').onclick = () => {
	if (grid_width < maximum_grid_width)
	{
		grid_width ++;
		grid_cell_count = grid_width * grid_width;
		initialize_game();
	}
};
document.getElementById('grid_down').onclick = () => {
	if (grid_width > minimum_grid_width)
	{
		grid_width --;
		grid_cell_count = grid_width * grid_width;
		initialize_game();
	}
};

/* Adjusts the color count. */
document.getElementById('color_up').onclick = () => {
	if (color_count < 6)
	{
		color_count ++;
		initialize_game();
	}
};
document.getElementById('color_down').onclick = () => {
	if (color_count > 3)
	{
		color_count --;
		initialize_game();
	}
};

/* Starting a brand new game. */
document.getElementById('reset_game').onclick = () => {
	initialize_game();
}

/* This is a test comment for Git pushing. */



//// EVENT LISTENERS

/* Generates the HTML for the tiles within the game grid upon loading the page. */
document.addEventListener(
	'DOMContentLoaded',
	() => {
		initialize_game();
	}
);

/* Checks if a tile was clicked. */
document.addEventListener(
	'mousedown',
	(event) => {
		/* Verifying that the clicked element is a tile. */
		const clicked_element = event.target;
		if (clicked_element.getAttribute('class') == 'tile')
		{
			tile_index = Number(clicked_element.getAttribute('id').substr(1));
			process_tile(clicked_element, tile_index);
		}
	}
);