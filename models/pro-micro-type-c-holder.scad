include <BOSL2/std.scad>

$fn = $preview ? 8 : 32;

FRONT_H = 14;
FLOOR = 1;
WALL = 1.4;
STRONG_WALL = 2;
LATCH_WALL = 3.4;

module pro_micro_type_c_plate() {
  PINS_SPACE = 5;
  LEN = 35.5;
  W = 9;
  H = 7;

  diff() cube([ W, LEN, FLOOR ], anchor = FWD + BOTTOM) {
    position(RIGHT + FWD + BOTTOM) right(PINS_SPACE)
        cube([ WALL, LEN, H ], anchor = LEFT + FWD + BOTTOM);
    position(LEFT + FWD + BOTTOM) left(PINS_SPACE)
        cube([ WALL, LEN, H ], anchor = RIGHT + FWD + BOTTOM);

    position(BACK + BOTTOM)
        cube([ W + 2 * PINS_SPACE + 2 * WALL, WALL, H - LATCH_WALL ],
             anchor = FWD + BOTTOM);
    position(FWD + BOTTOM)
        cube([ W + 2 * PINS_SPACE + 2 * WALL, STRONG_WALL, FRONT_H ],
             anchor = BACK + BOTTOM);
    position(FWD + BOTTOM)
        cube([ W + 2 * PINS_SPACE + 2 * WALL, STRONG_WALL, FRONT_H ],
             anchor = BACK + BOTTOM);
    tag("remove") position(FWD + BOTTOM) up(WALL + 1.5) type_c_hole(20, BOTTOM);
  }
}

module type_c_female_plate() {
  LEN = 16;
  WALL_LEN = 10;
  W = 6.4;
  H = 10;
  LOW_H = 5;

  diff() cube([ W, LEN, FLOOR ], anchor = FWD + BOTTOM) {
    position(RIGHT + FWD + BOTTOM)
        cube([ WALL, WALL_LEN, LOW_H ], anchor = LEFT + BOTTOM + FWD);
    position(LEFT + FWD + BOTTOM)
        cube([ WALL, WALL_LEN, H ], anchor = RIGHT + BOTTOM + FWD);

    position(FWD + BOTTOM)
        cube([ W + 2 * WALL, STRONG_WALL, FRONT_H ], anchor = BACK + BOTTOM);
    tag("remove") position(FWD + BOTTOM) up(WALL + 0.5) yrot(90)
        type_c_hole(20, RIGHT);
  }
}

module type_c_hole(depth, anchor, tolerance = 0.2) {
  usb_c_width = 9.1;
  usb_c_height = 3.5;

  cuboid([ usb_c_width + tolerance, depth, usb_c_height + tolerance ],
         anchor = anchor, rounding = 1);
}

module outer_latch(x_offset) {
  LOW_W = 28;
  LOW_H = 12;

  HIGH_W = 31;
  HIGH_H = 14;

  REMOVED_H = LOW_H;
  REMOVED_W = 26;

  diff() {
    move([ x_offset, -STRONG_WALL, 0 ])
        cube([ LOW_W, LATCH_WALL, LOW_H ], anchor = BACK + BOTTOM);
    move([ x_offset, -STRONG_WALL - LATCH_WALL, 0 ])
        cube([ HIGH_W, STRONG_WALL, HIGH_H ], anchor = BACK + BOTTOM);
    tag("remove") move([ x_offset, -STRONG_WALL, 0 ])
        cube([ REMOVED_W, LATCH_WALL + STRONG_WALL, REMOVED_H ],
             anchor = BACK + BOTTOM);
  }
}

module keyboard_holder() {
  pro_micro_type_c_plate();
  right(14.1) type_c_female_plate();
  outer_latch(4);
}

// right side
keyboard_holder();

// left side
// xflip() keyboard_holder();
