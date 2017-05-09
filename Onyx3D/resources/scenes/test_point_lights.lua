
include("resources/resources.lua")

skybox("sky")
	set_material("mat_sky")


default_camera("main_camera")
    set_position(0,0.7,1.5)
    set_rotation(0,0,0)

grid("grid");
	set_position(-5,0.01,-5)
	set_material("grey")

ambient_light(0.1,0.1,0.1)

node("pivot")
	set_rotation(0,0,0)
	



function createCube(index, x, z)
cube("w"..index)
	set_material("mat_wall")
	set_position(x,0.5,z)
end

--createCube(0,0,0)
	--set_scale(0.5,1,0.5)

createCube(10,-2,2)
createCube(11,-1,2)
createCube(12,0,2)
createCube(13,1,2)
createCube(14,2,2)

createCube(20,-2,-2)
createCube(21,-1,-2)
createCube(22,0,-2)
createCube(23,1,-2)
createCube(24,2,-2)

createCube(31,2,-1)
createCube(32,2,0)
createCube(33,2,1)

createCube(41,-2,-1)
createCube(42,-2,0)
createCube(43,-2,1)


for x=1,5 do
	for y=1,5 do
		quad("floor"..x.."-"..y)
			set_rotation(-90,0,0)
			set_material("mat_ceiling")
			set_position(x-2.5,0,y-2.5)
	end
end

for x=1,5 do
	for y=1,5 do
		quad("ceiling"..x.."-"..y)
			set_rotation(90,0,0)
			set_material("mat_ceiling")
			set_position(x-2.5,1,y-2.5)
	end
end

function createLight(index, x, y, z, cr,cg,cb, mat)
	octa("o"..index)
		set_scale(0.15,0.15,0.15)
		set_parent("pivot")
		set_material(mat)
		set_position(x*0.6,y,z*0.6)

	point_light("l"..index)
		set_parent("o"..index)	
		set_light_range(0.2)
		set_light_intensity(2)
		set_local_position(0,0,0)
		set_light_color(cr,cg,cb)
		set_light_specular(cr*1.5+0.5,cg*1.5+0.5,cb*1.5+0.5)
end

createLight(0,1,0.2,1, 0,1,0, "green")
createLight(1,-1,0.2,1, 1,0,0, "red")
createLight(2,0,0.2,-1.41, 0,0,1, "blue")

--[[
createLight(3,1,0.8,1, 0,1,0, "green")
createLight(4,-1,0.8,1, 1,0,0, "red")
createLight(5,0,0.8,-1.41, 0,0,1, "blue")
]]

model("mod_cyl", "resources/models/cylinder.obj")
	set_model_material("Cylinder", "mat_wall")


model_instance("cyl1", "mod_cyl")
	set_scale(0.2,0.5,0.2)
	
model_instance("cyl2", "mod_cyl")
	set_scale(0.2,0.5,0.2)
	set_position(0,0,-1.5)

model_instance("cyl3", "mod_cyl")
	set_scale(0.2,0.5,0.2)
	set_position(0,0,1.5)

model_instance("cyl4", "mod_cyl")
	set_scale(0.2,0.5,0.2)
	set_position(-1.5,0,0)

model_instance("cyl5", "mod_cyl")
	set_scale(0.2,0.5,0.2)
	set_position(1.5,0,0)


model_instance("cyl6", "mod_cyl")
	set_scale(0.2,0.5,0.2)
	set_position(-1.5,0,-1.5)

model_instance("cyl7", "mod_cyl")
	set_scale(0.2,0.5,0.2)
	set_position(1.5,0,1.5)

model_instance("cyl8", "mod_cyl")
	set_scale(0.2,0.5,0.2)
	set_position(-1.5,0,1.5)

model_instance("cyl9", "mod_cyl")
	set_scale(0.2,0.5,0.2)
	set_position(1.5,0,-1.5)


