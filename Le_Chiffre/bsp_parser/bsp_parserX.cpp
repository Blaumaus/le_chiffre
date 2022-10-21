///--------------------------------------------------------------------------------
///-- Author        ReactiioN
///-- Copyright     2016-2020, ReactiioN
///-- License       MIT
///--------------------------------------------------------------------------------
#define C1D4 std::printf("[!] unknown BSP version (%d), trying to parse it anyway...\n", _bsp_header.m_Version);
#define C1D3 ray_cast_surface(static_cast<std::int32_t>(_leaf_faces.at(leaf->first_leafface
#define C1D2 printf("[!] map has to many leafbrushes, parsed more than required...\n");
#define C1D1 printf("[!] map has to many leaffaces, parsed more than required...\n");
#define C1D0 std::printf("[!] %s isn't a (valid) .bsp file!\n", map_name.data());
#define C1CF static_cast<std::int32_t>(_leaf_brushes.at(leaf->first_leafbrush
#define C1CE std::printf("[!] failed to open file: %s\n", file_path.data());
#define C1CD std::printf("[+] Loading map: %s ...\n", map_name.data());
#define C1CC _vertices.at(_edges[-edge_index].v.at(1)).position;
#define C1CB printf("[!] map has no leafbrushes to parse...\n");
#define C1CA _vertices.at(_edges[edge_index].v.at(0)).position;
#define C1C9 destination(static_cast<std::size_t>(plane->type))
#define C1C8 printf("[!] map has no leaffaces to parse...\n");
#define C1C7 &_nodes.at(static_cast<std::size_t>(node_index));
#define C1C6 &_leaves.at(static_cast<std::size_t>(-node_index
#define C1C5 file.read(reinterpret_cast<char*>(&_bsp_header),
#define C1C4 (!valve::has_valid_bsp_ident(_bsp_header.ident))
#define C1C3 std::filesystem::path(input).generic_string();
#define C1C2 origin(static_cast<std::size_t>(plane->type))
#define C1C1 edge_plane->origin.dot(polygon->verts.at(i));
#define C1C0 ray_cast_node(node->children.at(!side_id),
#define C1BF std::shared_lock<std::shared_timed_mutex>
#define C1BE std::unique_lock<std::shared_timed_mutex>
#define C1BD ray_cast_node(node->children.at(side_id),
#define C1BC static_cast<std::size_t>(surface_index);
#define C1BB /* convert seperators from DOS to UNIX*/
#define C1BA _planes.at(surface.plane_num).distance;
#define C1B9 static_cast<std::uint8_t>(plane_bits);
#define C1B8 _planes.at(surface.plane_num).normal;
#define C1B7 static_cast<std::size_t>(num_edges);
#define C1B6 ray_cast_node(node->children.at(1),
#define C1B5 static_cast<std::uint8_t>(in.type);
#define C1B4 &_planes.at(brush_side->plane_num);
#define C1B3 _polygons.resize(_surfaces.size());
#define C1B2 ray_cast_node(node->children.at(0),
#define C1B1 bsp_parser::bsp_parser(bsp_parser&&
#define C1B0 .append(fix_seperators(map_name));
#define C1AF &_brush_sides.at(brush->first_side
#define C1AE valve::lump_index::leaf_brushes,
#define C1AD edge_plane->origin.normalize();
#define C1AC valve::lump_index::brush_sides,
#define C1AB (edge_plane->dist(intersection)
#define C1AA bsp_parser::parse_leafbrushes(
#define C1A9 static_cast<std::ptrdiff_t>(-1
#define C1A8 _planes.resize(planes.size());
#define C1A7 (edge_plane->origin.is_zero())
#define C1A6 destination.dot(plane->normal)
#define C1A5 valve::lump_index::leaf_faces,
#define C1A4 static_cast<size_t>(num_edges)
#define C1A3 valve::lump_index::surfedges,
#define C1A2 std::memset(&rhs._bsp_header,
#define C1A1 _polygons.push_back(polygon);
#define C1A0 std::move(rhs._leaf_brushes);
#define C19F bsp_parser::ray_cast_surface(
#define C19E static_cast<std::int32_t>(j);
#define C19D bsp_parser::set_current_map(
#define C19C std::move(rhs._brush_sides);
#define C19B std::vector<valve::dplane_t>
#define C19A valve::lump_index::tex_info,
#define C199 &polygon->edge_planes.at(i);
#define C198 bsp_parser::parse_leaffaces(
#define C197 (!set_current_map(directory,
#define C196 valve::lump_index::vertices,
#define C195 bsp_parser::parse_polygons()
#define C194 bsp_parser::ray_cast_brush(
#define C193 valve::lump_index::brushes,
#define C192 valve::MAX_MAP_LEAFBRUSHES)
#define C191 std::move(rhs._surf_edges);
#define C190 std::move(rhs._leaf_faces);
#define C18F std::vector<valve::dnode_t>
#define C18E &_brushes.at(brush_index);
#define C18D valve::MAX_SURFINFO_VERTS)
#define C18C valve::lump_index::planes,
#define C18B bsp_parser::ray_cast_node(
#define C18A sizeof(valve::dheader_t));
#define C189 std::move(rhs._tex_infos);
#define C188 plane->dist(destination);
#define C187 fix_seperators(directory)
#define C186 _surf_edges.at(first_edge
#define C185 std::move(rhs._polygons);
#define C184 bsp_parser::parse_planes(
#define C183 valve::lump_index::leafs,
#define C182 valve::lump_index::nodes,
#define C181 valve::lump_index::faces,
#define C180 out->fraction_left_solid)
#define C17F origin.dot(plane->normal)
#define C17E (out->fraction_left_solid
#define C17D valve::lump_index::edges,
#define C17C std::move(rhs._vertices);
#define C17B std::move(rhs._surfaces);
#define C17A _nodes.resize(num_nodes);
#define C179 std::max((start_distance
#define C178 bsp_parser::parse_nodes(
#define C177 out->fraction_left_solid
#define C176 std::move(rhs._brushes);
#define C175 std::move(rhs._planes);
#define C174 parse_leafbrushes(file)
#define C173 valve::MASK_SHOT_HULL))
#define C172 std::move(rhs._leaves);
#define C171 std::ios_base::binary);
#define C170 bsp_parser::is_visible(
#define C16F bsp_parser::trace_ray(
#define C16E std::move(rhs._edges);
#define C16D (_bsp_header.m_Version
#define C16C leaf->num_leafbrushes;
#define C16B std::move(rhs._nodes);
#define C16A polygon.plane.distance
#define C169 ray_cast_brush(brush,
#define C168 polygon->num_verts));
#define C167 &_polygons.at(index);
#define C166 valve::DIST_EPSILON),
#define C165 parse_leaffaces(file)
#define C164 sizeof(_bsp_header));
#define C163 (polygon->verts.at(i)
#define C162 bsp_parser::load_map(
#define C161 polygon.plane.origin
#define C160 bsp_parser::operator
#define C15F edge_plane->distance
#define C15E valve::DIST_EPSILON)
#define C15D leaf->num_leaffaces;
#define C15C plane->dist(origin);
#define C15B out->num_brush_sides
#define C15A polygon->verts.at((i
#define C159 polygon->num_verts)
#define C158 _leaf_faces.size();
#define C157 surface.first_edge;
#define C156 polygon.verts.at(i)
#define C155 polygon->num_verts;
#define C154 inversed_distance;
#define C153 in.children.at(j);
#define C152 fraction_to_leave;
#define C151 fraction_to_leave)
#define C150 (!parse_lump(file,
#define C14F (fraction_to_leave
#define C14E (fraction_to_enter
#define C14D brush_side->bevel)
#define C14C fraction_to_enter)
#define C14B (directory.empty()
#define C14A (brush->num_sides)
#define C149 out.children.at(j)
#define C148 parse_planes(file)
#define C147 edge_plane->origin
#define C146 fraction_to_enter;
#define C145 surface.num_edges;
#define C144 valve::BSPVERSION)
#define C143 !(brush->contents
#define C142 parse_nodes(file)
#define C141 polygon.num_verts
#define C140 (surface.tex_info
#define C13F trace_ray(origin,
#define C13E _polygons.size())
#define C13D brush->num_sides;
#define C13C (out->start_solid
#define C13B (!_planes.empty()
#define C13A fraction_to_enter
#define C139 fraction_to_leave
#define C138 inversed_distance
#define C137 lock(rhs._mutex);
#define C136 map_name.empty())
#define C135 out.leaf_children
#define C134 out.node_children
#define C133 !(trace.fraction
#define C132 brush->contents;
#define C131 &polygon->plane;
#define C130 (!num_leaffaces)
#define C12F plane->distance;
#define C12E parse_lump(file,
#define C12D fraction_second;
#define C12C parse_polygons()
#define C12B ray_cast_node(0,
#define C12A (fraction_second
#define C129 valve::dbrush_t*
#define C128 fraction_middle,
#define C127 out->start_solid
#define C126 rhs._bsp_header;
#define C125 fraction_first;
#define C124 valve::trace_t*
#define C123 fraction_first,
#define C122 start_fraction)
#define C121 _leaf_brushes))
#define C120 std::move(rhs);
#define C11F fraction_second
#define C11E start_fraction,
#define C11D (destination(i)
#define C11C start_distance,
#define C11B start_distance)
#define C11A (fraction_first
#define C119 (start_distance
#define C118 file(file_path,
#define C117 fraction_middle
#define C116 out->end_pos(i)
#define C115 in.first_face;
#define C114 planes.size();
#define C113 valve::trace_t
#define C112 valve::polygon
#define C111 std::ifstream&
#define C110 out->all_solid
#define C10F (num_leaffaces
#define C10E (out->fraction
#define C10D (out.normal(j)
#define C10C _leaves.data()
#define C10B start_fraction
#define C10A out.first_face
#define C109 surface_index,
#define C108 (std::uint16_t
#define C107 out->fraction)
#define C106 end_distance);
#define C105 _planes.at(i);
#define C104 _planes.data()
#define C103 start_distance
#define C102 fraction_first
#define C101 fix_seperators
#define C100 _brush_sides)
#define CFF in.normal(j);
#define CFE in.num_faces;
#define CFD in.plane_num;
#define CFC _leaf_brushes
#define CFB intersection;
#define CFA end_distance)
#define CF9 lock(_mutex);
#define CF8 out->clear();
#define CF7 (!starts_out)
#define CF6 _leaf_faces))
#define CF5 out.sign_bits
#define CF4 out.plane_num
#define CF3 (bsp_parser&&
#define CF2 out.num_faces
#define CF1 nodes.size();
#define CF0 out.normal(j)
#define CEF (end_distance
#define CEE (end_fraction
#define CED end_distance;
#define CEC end_fraction,
#define CEB num_leaffaces
#define CEA _nodes.at(i);
#define CE9 _nodes.data()
#define CE8 child_index);
#define CE7 std::ifstream
#define CE6 out->fraction
#define CE5 planes.at(i);
#define CE4 plane->origin
#define CE3 out->contents
#define CE2 (destination
#define CE1 nodes.at(i);
#define CE0 node->plane;
#define CDF (!brush_side
#define CDE child_index;
#define CDD intersection
#define CDC std::string&
#define CDB (std::size_t
#define CDA (starts_out)
#define CD9 .append("/")
#define CD8 out.distance
#define CD7 (plane->type
#define CD6 end_distance
#define CD5 (child_index
#define CD4 std::int32_t
#define CD3 _brush_sides
#define CD2 in.distance;
#define CD1 FLT_EPSILON)
#define CD0 _surf_edges)
#define CCF out->end_pos
#define CCE destination,
#define CCD _bsp_header
#define CCC (!ends_out)
#define CCB _leaf_faces
#define CCA std::string
#define CC9 std::size_t
#define CC8 (edge_index
#define CC7 _surf_edges
#define CC6 /*/ Front*/
#define CC5 file_path))
#define CC4 node_index,
#define CC3 destination
#define CC2 bsp_parser&
#define CC1 child_index
#define CC0 _tex_infos)
#define CBF brush_index
#define CBE (node_index
#define CBD origin(i));
#define CBC first_edge
#define CBB edge_index
#define CBA plane_bits
#define CB9 num_edges;
#define CB8 num_nodes;
#define CB7 out->brush
#define CB6 file_path;
#define CB5 _vertices)
#define CB4 directory,
#define CB3 /*/ Back*/
#define CB2 starts_out
#define CB1 brush_side
#define CB0 (num_edges
#define CAF _tex_infos
#define CAE _surfaces)
#define CAD edge_plane
#define CAC _map_name)
#define CAB (final(i)
#define CAA namespace
#define CA9 _polygons
#define CA8 origin(i)
#define CA7 out.plane
#define CA6 map_name,
#define CA5 fraction;
#define CA4 _surfaces
#define CA3 file_path
#define CA2 _brushes)
#define CA1 _vertices
#define CA0 map_name;
#define C9F continue;
#define C9E _map_name
#define C9D num_edges
#define C9C middle(i)
#define C9B (map_name
#define C9A (fraction
#define C99 num_nodes
#define C98 ends_out
#define C97 out.maxs
#define C96 out.mins
#define C95 out.type
#define C94 planes))
#define C93 polygon;
#define C92 side_id;
#define C91 noexcept
#define C90 _leaves)
#define C8F fraction
#define C8E trace{};
#define C8D _brushes
#define C8C &trace);
#define C8B (!plane)
#define C8A [](const
#define C89 in.maxs;
#define C88 in.mins;
#define C87 nullptr;
#define C86 map_name
#define C85 vector3&
#define C84 vector3
#define C83 (!file)
#define C82 (!brush
#define C81 nodes))
#define C80 _edges)
#define C7F return;
#define C7E surface
#define C7D planes;
#define C7C polygon
#define C7B (!node)
#define C7A _leaves
#define C79 side_id
#define C78 _planes
#define C77 origin)
#define C76 origin,
#define C75 middle;
#define C74 middle,
#define C73 brush,
#define C72 input)
#define C71 static
#define C70 -99.f;
#define C6F (const
#define C6E final,
#define C6D origin
#define C6C brush;
#define C6B (index
#define C6A _nodes
#define C69 const*
#define C68 nodes;
#define C67 return
#define C66 _edges
#define C65 false;
#define C64 *this;
#define C63 break;
#define C62 final;
#define C61 dot2);
#define C60 auto&
#define C5F edge;
#define C5E float
#define C5D -99.f
#define C5C const
#define C5B 1.f);
#define C5A catch
#define C59 1.0f;
#define C58 1.0f)
#define C57 0.2f;
#define C56 0.0f)
#define C55 0.f);
#define C54 brush
#define C53 *this
#define C52 (dot1
#define C51 (auto
#define C50 (...)
#define C4F out);
#define C4E true;
#define C4D using
#define C4C index
#define C4B plane
#define C4A auto*
#define C49 1.f,
#define C48 0.f,
#define C47 1.f;
#define C46 auto
#define C45 1));
#define C44 file
#define C43 i)),
#define C42 dot1
#define C41 1.0f
#define C40 dot2
#define C3F edge
#define C3E ++j)
#define C3D i));
#define C3C 0.f)
#define C3B rhs)
#define C3A 0.f;
#define C39 i++)
#define C38 else
#define C37 bool
#define C36 node
#define C35 ++i)
#define C34 out)
#define C33 leaf
#define C32 1.f)
#define C31 void
#define C30 0.f
#define C2F rn;
#define C2E out
#define C2D i);
#define C2C try
#define C2B for
#define C2A 1.f
#define C29 (i
#define C28 in
#define C27 if
#define C26 (;
#define C25 3)
#define C24 !=
#define C23 2;
#define C22 1;
#define C21 (t
#define C20 1)
#define C1F >=
#define C1E ==
#define C1D <=
#define C1C <<
#define C1B 3;
#define C1A 0;
#define C19 &&
#define C18 t;
#define C17 0,
#define C16 0)
#define C15 |=
#define C14 ||
#define C13 };
#define C12 1
#define C11 =
#define C10 )
#define CF &
#define CE <
#define CD ;
#define CC :
#define CB %
#define CA +
#define C9 t
#define C8 3
#define C7 -
#define C6 j
#define C5 /
#define C4 {
#define C3 i
#define C2 *
#define C1 }
#define C0 >
#include "valve-bsp-parser/bsp_parser.hpp"
#include <filesystem>
#define C1D5 C4D CAA C2F C1B1 C3B C91 C4 C53 C11 C120
#define C1D6 C1 CC2 C160 C11 CF3 C3B C91 C4 C1BE C137
#define C1D7 CCD C11 C126 C1A2 C17 C18A CA1 C11 C17C C78
#define C1D8 C11 C175 C66 C11 C16E CC7 C11 C191 C7A C11
#define C1D9 C172 C6A C11 C16B CA4 C11 C17B CAF C11 C189
#define C1DA C8D C11 C176 CD3 C11 C19C CCB C11 C190 CFC
#define C1DB C11 C1A0 CA9 C11 C185 C67 C64 C1 C37 C19D
#define C1DC C5C CDC CB4 C5C CDC CA6 CDC CA3 C10 C4
#define C1DD C71 C46 C101 C11 C8A CDC C72 C4 C1BB C67
#define C1DE C1C3 C13 C27 C14B C14 C136 C4 C67 C65 C1
#define C1DF CA3 C11 C187 CD9 C1B0 C9E C11 CA0 
#define C1E0 C1D5 C1D6 C1D7 C1D8 C1D9 C1DA C1DB C1DC C1DD C1DE
#define C1E1 C1DF 
#define C1E2 C1E0 C1E1 
#define C1E3(__FOX__) __FOX__
C1E3(C1E2)
#if defined(RN_BSP_PARSER_MESSAGES)
#define C1E4 C1CD 
#define C1E5(__FOX__) __FOX__
C1E5(C1E4)
#endif
#define C1E6 C67 C4E C1 C37 C184 C111 C44 C10 C4 C19B
#define C1E7 C7D C27 C150 C18C C94 C4 C67 C65 C1 C1A8
#define C1E8 C2B CDB C3 C11 C1A C3 CE C114 C35 C4
#define C1E9 C60 C2E C11 C105 C5C C60 C28 C11 CE5 C46
#define C1EA CBA C11 C1A C2B CDB C6 C11 C1A C6 CE
#define C1EB C1B C3E C4 CF0 C11 CFF C27 C10D CE C3C
#define C1EC C4 CBA C15 C12 C1C C19E C1 C1 CD8 C11
#define C1ED CD2 C95 C11 C1B5 CF5 C11 C1B9 C1 C67 C4E
#define C1EE C1 C37 C178 C111 C44 C10 C4 C18F C68 C27
#define C1EF C150 C182 C81 C4 C67 C65 C1 C5C C46 C99
#define C1F0 C11 CF1 C17A C2B CDB C3 C11 C1A C3 CE
#define C1F1 CB8 C35 C4 C5C C60 C28 C11 CE1 C60 C2E
#define C1F2 C11 CEA C96 C11 C88 C97 C11 C89 CF4 C11
#define C1F3 CFD CA7 C11 C104 CA CFD C10A C11 C115 CF2
#define C1F4 C11 CFE C2B CDB C6 C11 C1A C6 CE C23
#define C1F5 C3E C4 C5C C46 CC1 C11 C153 C149 C11 CDE
#define C1F6 C27 CD5 C1F C16 C4 C135 C11 C87 C134 C11
#define C1F7 CE9 CA CDE C1 C38 C4 C135 C11 C10C CA
#define C1F8 C1A9 C7 CE8 C134 C11 C87 C1 C1 C1 C67
#define C1F9 C4E C1 C37 C198 C111 C44 C10 C4 C27 C150
#define C1FA C1A5 CF6 C4 C67 C65 C1 C5C C46 CEB C11
#define C1FB C158 C27 C10F C0 C192 C4 C1D1 C1 C38 C27
#define C1FC C130 C4 C1C8 C1 C67 C4E C1 C37 C1AA C111
#define C1FD C44 C10 C4 C27 C150 C1AE C121 C4 C67 C65
#define C1FE C1 C5C C46 CEB C11 C158 C27 C10F C0 C192
#define C1FF C4 C1D2 C1 C38 C27 C130 C4 C1CB C1 C67
#define C200 C4E C1 C37 C195 C4 C1B3 C2B C6F C60 C7E
#define C201 CC CAE C4 C5C C60 CBC C11 C157 C5C C60
#define C202 C9D C11 C145 C27 CB0 CE C8 C14 C1A4 C0
#define C203 C18D C4 C9F C1 C27 C140 C1D C16 C4 C9F
#define C204 C1 C112 C93 C84 C5F C2B C51 C3 C11 C1A
#define C205 C3 CE CB9 C35 C4 C5C C46 CBB C11 C186
#define C206 CA C2D C27 CC8 C1F C16 C4 C3F C11 C1CA
#define C207 C1 C38 C4 C3F C11 C1CC C1 C156 C11 C5F
#define C208 C1 C141 C11 C1B7 C161 C11 C1B8 C16A C11 C1BA
#define C209 C1A1 C1 C67 C4E C1 C31 C18B C5C CD4 CC4
#define C20A C5C C5E C11E C5C C5E CEC C5C C85 C76 C5C
#define C20B C85 CCE C124 C2E C10 C4 C27 C10E C1D C122
#define C20C C4 C7F C1 C27 CBE CE C16 C4 C4A C33
#define C20D C11 C1C6 C7 C45 C2B C108 C3 C11 C1A C3
#define C20E CE C16C C35 C4 C5C C46 CBF C11 C1CF CA
#define C20F C3D C4A C54 C11 C18E C27 C82 C14 C143 CF
#define C210 C173 C4 C9F C1 C169 C76 CCE C4F C27 C10E
#define C211 C1E C3C C4 C7F C1 CB7 C11 C6C C1 C27
#define C212 C13C C14 CE6 CE C32 C4 C7F C1 C2B C108
#define C213 C3 C11 C1A C3 CE C15D C35 C4 C1D3 CA
#define C214 C43 C76 CCE C4F C1 C7F C1 C4A C36 C11
#define C215 C1C7 C27 C7B C4 C7F C1 C4A C4B C11 CE0
#define C216 C27 C8B C4 C7F C1 C5E C11C CED C27 CD7
#define C217 CE C25 C4 C103 C11 C1C2 C7 C12F CD6 C11
#define C218 C1C9 C7 C12F C1 C38 C4 C103 C11 C17F C7
#define C219 C12F CD6 C11 C1A6 C7 C12F C1 C27 C119 C1F
#define C21A C30 C19 CD6 C1F C3C C4 C1B2 C11E CEC C76
#define C21B CCE C4F C1 C38 C27 C119 CE C30 C19 CD6
#define C21C CE C3C C4 C1B6 C11E CEC C76 CCE C4F C1
#define C21D C38 C4 CD4 C92 C5E C123 C12D C84 C75 C27
#define C21E C119 CE CFA C4 CB3 C79 C11 C22 C5C C46
#define C21F C138 C11 C2A C5 C119 C7 C106 C102 C11 C119
#define C220 CA CD1 C2 C154 C11F C11 C119 CA CD1 C2
#define C221 C154 C1 C38 C27 CEF CE C11B C4 CC6 C79
#define C222 C11 C1A C5C C46 C138 C11 C41 C5 C119 C7
#define C223 C106 C102 C11 C119 CA CD1 C2 C154 C11F C11
#define C224 C119 C7 CD1 C2 C154 C1 C38 C4 CC6 C79
#define C225 C11 C1A C102 C11 C47 C11F C11 C3A C1 C27
#define C226 C11A CE C3C C4 C102 C11 C3A C1 C38 C27
#define C227 C11A C0 C32 C4 C102 C11 C47 C1 C27 C12A
#define C228 CE C3C C4 C11F C11 C3A C1 C38 C27 C12A
#define C229 C0 C32 C4 C11F C11 C47 C1 C46 C117 C11
#define C22A C10B CA CEE C7 C122 C2 C125 C2B CDB C3
#define C22B C11 C1A C3 CE C1B C39 C4 C9C C11 CA8
#define C22C CA C102 C2 C11D C7 CBD C1 C1BD C11E C128
#define C22D C76 C74 C4F C117 C11 C10B CA CEE C7 C122
#define C22E C2 C12D C2B CDB C3 C11 C1A C3 CE C1B
#define C22F C39 C4 C9C C11 CA8 CA C11F C2 C11D C7
#define C230 CBD C1 C1C0 C128 CEC C74 CCE C4F C1 C1
#define C231 C31 C194 C129 C73 C5C C85 C76 C5C C85 CCE
#define C232 C124 C2E C10 C5C C4 C27 C14A C4 C46 C13A
#define C233 C11 C70 C46 C139 C11 C47 C46 CB2 C11 C65
#define C234 C46 C98 C11 C65 C2B C51 C3 C11 C1A C3
#define C235 CE C13D C35 C4 C46 C69 CB1 C11 C1AF CA
#define C236 C2D C27 CDF C14 C14D C4 C9F C1 C46 C69
#define C237 C4B C11 C1B4 C27 C8B C4 C9F C1 C5C C46
#define C238 C103 C11 C17F C7 C12F C5C C46 CD6 C11 C1A6
#define C239 C7 C12F C27 C119 C0 C3C C4 CB2 C11 C4E
#define C23A C27 CEF C0 C3C C4 C7F C1 C1 C38 C4
#define C23B C27 CEF C1D C3C C4 C9F C1 C98 C11 C4E
#define C23C C1 C27 C119 C0 CFA C4 C46 C8F C11 C179
#define C23D C7 C166 C55 C8F C11 C8F C5 C119 C7 C106
#define C23E C27 C9A C0 C14C C4 C13A C11 CA5 C1 C1
#define C23F C38 C4 C5C C46 C8F C11 C119 CA C15E C5
#define C240 C119 C7 C106 C27 C9A CE C151 C4 C139 C11
#define C241 CA5 C1 C1 C1 C27 CDA C4 C27 C17E C7
#define C242 C13A C0 C3C C4 CB2 C11 C65 C1 C1 C15B
#define C243 C11 C13D C27 CF7 C4 C127 C11 C4E CE3 C11
#define C244 C132 C27 CCC C4 C110 C11 C4E CE6 C11 C3A
#define C245 C177 C11 C47 C1 C38 C4 C27 C14F C24 C2A
#define C246 C19 C139 C0 C180 C4 C177 C11 C152 C27 C10E
#define C247 C1D C151 C4 CE6 C11 C47 C1 C1 C1 C7F
#define C248 C1 C27 C14E CE C151 C4 C27 C14E C0 C5D
#define C249 C19 C13A CE C107 C4 C27 C14E CE C3C C4
#define C24A C13A C11 C3A C1 CE6 C11 C146 CB7 C11 C6C
#define C24B CE3 C11 C132 C1 C1 C1 C1 C31 C19F C5C
#define C24C CD4 C109 C5C C85 C76 C5C C85 CCE C124 C2E
#define C24D C10 C4 C5C C46 C4C C11 C1BC C27 C6B C1F
#define C24E C13E C4 C7F C1 C4A C7C C11 C167 C4A C4B
#define C24F C11 C131 C5C C46 C42 C11 C15C C5C C46 C40
#define C250 C11 C188 C27 C52 C0 C30 C24 C40 C0 C3C
#define C251 C4 C27 C52 C7 C40 CE C15E C4 C7F C1
#define C252 C5C C46 C9 C11 C42 C5 C52 C7 C61 C27
#define C253 C21 C1D C16 C4 C7F C1 CC9 C3 C11 C1A
#define C254 C5C C46 CDD C11 C6D CA CE2 C7 C77 C2
#define C255 C18 C2B C26 C3 CE C155 C35 C4 C4A CAD
#define C256 C11 C199 C27 C1A7 C4 C147 C11 CE4 C7 C163
#define C257 C7 C15A CA C20 CB C168 C1AD C15F C11 C1C1
#define C258 C1 C27 C1AB CE C56 C4 C63 C1 C1 C27
#define C259 C29 C1E C159 C4 CE6 C11 C57 CCF C11 CFB
#define C25A C1 C1 C1 C37 C162 C5C CDC CB4 C5C CDC
#define C25B C86 C10 C4 C27 C9B C1E CAC C4 C67 C4E
#define C25C C1 C1BE CF9 CCA CB6 C27 C197 CA6 CC5 C4
#define C25D C67 C65 C1 CE7 C118 C171 C27 C83 C4 
#define C25E C1E6 C1E7 C1E8 C1E9 C1EA C1EB C1EC C1ED C1EE C1EF
#define C25F C1F0 C1F1 C1F2 C1F3 C1F4 C1F5 C1F6 C1F7 C1F8 C1F9
#define C260 C1FA C1FB C1FC C1FD C1FE C1FF C200 C201 C202 C203
#define C261 C204 C205 C206 C207 C208 C209 C20A C20B C20C C20D
#define C262 C20E C20F C210 C211 C212 C213 C214 C215 C216 C217
#define C263 C218 C219 C21A C21B C21C C21D C21E C21F C220 C221
#define C264 C222 C223 C224 C225 C226 C227 C228 C229 C22A C22B
#define C265 C22C C22D C22E C22F C230 C231 C232 C233 C234 C235
#define C266 C236 C237 C238 C239 C23A C23B C23C C23D C23E C23F
#define C267 C240 C241 C242 C243 C244 C245 C246 C247 C248 C249
#define C268 C24A C24B C24C C24D C24E C24F C250 C251 C252 C253
#define C269 C254 C255 C256 C257 C258 C259 C25A C25B C25C C25D
#define C26A C25E C25F C260 C261 C262 C263 C264 C265 C266 C267
#define C26B C268 C269 
#define C26C C26A C26B 
#define C26D(__FOX__) __FOX__
C26D(C26C)
#if defined(RN_BSP_PARSER_MESSAGES)
#define C26E C1CE 
#define C26F(__FOX__) __FOX__
C26F(C26E)
#endif
#define C270 C67 C65 C1 C2C C4 C1C5 C164 
#define C271(__FOX__) __FOX__
C271(C270)
#if defined(RN_BSP_PARSER_MESSAGES)
#define C272 C27 C16D CE C144 C4 C1D4 C1 
#define C273(__FOX__) __FOX__
C273(C272)
#endif
#define C274 C27 C1C4 C4 
#define C275(__FOX__) __FOX__
C275(C274)
#if defined(RN_BSP_PARSER_MESSAGES)
#define C276 C1D0 
#define C277(__FOX__) __FOX__
C277(C276)
#endif
#define C278 C67 C65 C1 C67 C12E C196 CB5 C19 C148 C19
#define C279 C12E C17D C80 C19 C12E C1A3 CD0 C19 C12E C183
#define C27A C90 C19 C142 C19 C12E C181 CAE C19 C12E C19A
#define C27B CC0 C19 C12E C193 CA2 C19 C12E C1AC C100 C19
#define C27C C165 C19 C174 C19 C12C CD C1 C5A C50 C4
#define C27D C67 C65 C1 C1 C37 C170 C5C C85 C76 C5C
#define C27E C85 CC3 C10 C4 C1BF CF9 C113 C8E C13F CCE
#define C27F C8C C67 C133 CE C5B C1 C31 C16F C5C C85
#define C280 C76 C5C C84 CF C6E C124 C2E C10 C4 C27
#define C281 C13B C19 C34 C4 CF8 CE6 C11 C59 C177 C11
#define C282 C3A C12B C48 C49 C76 C6E C4F C27 C10E CE
#define C283 C58 C4 C2B CDB C3 C11 C1A C3 CE C1B
#define C284 C35 C4 C116 C11 CA8 CA CE6 C2 CAB C7
#define C285 CBD C1 C1 C38 C4 CCF C11 C62 C1 C1
#define C286 C1 
#define C287 C278 C279 C27A C27B C27C C27D C27E C27F C280 C281
#define C288 C282 C283 C284 C285 C286 
#define C289 C287 C288 
#define C28A(__FOX__) __FOX__
C28A(C289)
