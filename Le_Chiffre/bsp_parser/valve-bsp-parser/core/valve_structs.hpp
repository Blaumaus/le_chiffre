//--------------------------------------------------------------------------------
//-- Author        ReactiioN
//-- Copyright     2016-2020, ReactiioN
//-- License       MIT
//--------------------------------------------------------------------------------
#pragma once

#include "matrix.hpp"

namespace rn::valve {
    constexpr bool has_valid_bsp_ident(
        const std::int32_t ident
        )
    {
        return ident >= ('P' << 24) + ('S' << 16) + ('B' << 8) + 'V';
    }

    constexpr std::int32_t MAX_BRUSH_LIGHTMAP_DIM_WITHOUT_BORDER = 32;
    constexpr std::int32_t MAX_BRUSH_LIGHTMAP_DIM_INCLUDING_BORDER = 35;
    constexpr std::int32_t MAX_DISP_LIGHTMAP_DIM_WITHOUT_BORDER = 128;
    constexpr std::int32_t MAX_DISP_LIGHTMAP_DIM_INCLUDING_BORDER = 131;
    constexpr std::int32_t MAX_LIGHTMAP_DIM_WITHOUT_BORDER = MAX_DISP_LIGHTMAP_DIM_WITHOUT_BORDER;
    constexpr std::int32_t MAX_LIGHTMAP_DIM_INCLUDING_BORDER = MAX_DISP_LIGHTMAP_DIM_INCLUDING_BORDER;

    constexpr float        DIST_EPSILON = 0.03125f;
    constexpr std::size_t  MAX_SURFINFO_VERTS = 32;
    constexpr std::int32_t BSPVERSION = 19;
    constexpr std::size_t  HEADER_LUMPS = 64;
    constexpr std::size_t  MAX_POLYGONS = 50120;
    constexpr std::size_t  MAX_MOD_KNOWN = 512;
    constexpr std::size_t  MAX_MAP_MODELS = 1024;
    constexpr std::size_t  MAX_MAP_BRUSHES = 8192;
    constexpr std::size_t  MAX_MAP_ENTITIES = 4096;
    constexpr std::size_t  MAX_MAP_ENTSTRING = 256 * 1024;
    constexpr std::size_t  MAX_MAP_NODES = 65536;
    constexpr std::size_t  MAX_MAP_TEXINFO = 12288;
    constexpr std::size_t  MAX_MAP_TEXDATA = 2048;
    constexpr std::size_t  MAX_MAP_LEAFBRUSHES = 65536;
    constexpr std::size_t  MIN_MAP_DISP_POWER = 2;
    constexpr std::size_t  MAX_MAP_DISP_POWER = 4;
    constexpr std::size_t  MAX_MAP_SURFEDGES = 512000;
    constexpr std::size_t  MAX_DISP_CORNER_NEIGHBORS = 4;

    // NOTE: These are stored in a short in the engine now.  Don't use more than 16 bits
    constexpr std::int32_t SURF_LIGHT = 0x0001; // value will hold the light strength
    constexpr std::int32_t SURF_SLICK = 0x0002; // effects game physics
    constexpr std::int32_t SURF_SKY = 0x0004; // don't draw, but add to skybox
    constexpr std::int32_t SURF_WARP = 0x0008; // turbulent water warp
    constexpr std::int32_t SURF_TRANS = 0x0010;
    constexpr std::int32_t SURF_WET = 0x0020; // the surface is wet
    constexpr std::int32_t SURF_FLOWING = 0x0040; // scroll towards angle
    constexpr std::int32_t SURF_NODRAW = 0x0080; // don't bother referencing the texture
    constexpr std::int32_t SURF_Hint32_t = 0x0100; // make a primary bsp splitter
    constexpr std::int32_t SURF_SKIP = 0x0200; // completely ignore, allowing non-closed brushes
    constexpr std::int32_t SURF_NOLIGHT = 0x0400; // Don't calculate light
    constexpr std::int32_t SURF_BUMPLIGHT = 0x0800; // calculate three lightmaps for the surface for bumpmapping
    constexpr std::int32_t SURF_HITBOX = 0x8000; // surface is part of a hitbox

    constexpr std::int32_t CONTENTS_EMPTY = 0;           // No contents
    constexpr std::int32_t CONTENTS_SOLID = 0x1;         // an eye is never valid in a solid
    constexpr std::int32_t CONTENTS_WINDOW = 0x2;         // translucent, but not watery (glass)
    constexpr std::int32_t CONTENTS_AUX = 0x4;
    constexpr std::int32_t CONTENTS_GRATE = 0x8;         // alpha-tested "grate" textures.  Bullets/sight pass through, but solids don't
    constexpr std::int32_t CONTENTS_SLIME = 0x10;
    constexpr std::int32_t CONTENTS_WATER = 0x20;
    constexpr std::int32_t CONTENTS_MIST = 0x40;
    constexpr std::int32_t CONTENTS_OPAQUE = 0x80;        // things that cannot be seen through (may be non-solid though)
    constexpr std::int32_t LAST_VISIBLE_CONTENTS = 0x80;
    constexpr std::int32_t ALL_VISIBLE_CONTENTS = LAST_VISIBLE_CONTENTS | LAST_VISIBLE_CONTENTS - 1;
    constexpr std::int32_t CONTENTS_TESTFOGVOLUME = 0x100;
    constexpr std::int32_t CONTENTS_UNUSED3 = 0x200;
    constexpr std::int32_t CONTENTS_UNUSED4 = 0x400;
    constexpr std::int32_t CONTENTS_UNUSED5 = 0x800;
    constexpr std::int32_t CONTENTS_UNUSED6 = 0x1000;
    constexpr std::int32_t CONTENTS_UNUSED7 = 0x2000;
    constexpr std::int32_t CONTENTS_MOVEABLE = 0x4000;      // hits entities which are MOVETYPE_PUSH (doors, plats, etc.)
    // remaining contents are non-visible, and don't eat brushes
    constexpr std::int32_t CONTENTS_AREAPORTAL = 0x8000;
    constexpr std::int32_t CONTENTS_PLAYERCLIP = 0x10000;
    constexpr std::int32_t CONTENTS_MONSTERCLIP = 0x20000;
    // currents can be added to any other contents, and may be mixed
    constexpr std::int32_t CONTENTS_CURRENT_0 = 0x40000;
    constexpr std::int32_t CONTENTS_CURRENT_90 = 0x80000;
    constexpr std::int32_t CONTENTS_CURRENT_180 = 0x100000;
    constexpr std::int32_t CONTENTS_CURRENT_270 = 0x200000;
    constexpr std::int32_t CONTENTS_CURRENT_UP = 0x400000;
    constexpr std::int32_t CONTENTS_CURRENT_DOWN = 0x800000;
    constexpr std::int32_t CONTENTS_ORIGIN = 0x1000000;   // removed before bsping an entity
    constexpr std::int32_t CONTENTS_MONSTER = 0x2000000;   // should never be on a brush, only in game
    constexpr std::int32_t CONTENTS_DEBRIS = 0x4000000;
    constexpr std::int32_t CONTENTS_DETAIL = 0x8000000;   // brushes to be added after vis leafs
    constexpr std::int32_t CONTENTS_TRANSLUCENT = 0x10000000;  // int32_t set if any surface has trans
    constexpr std::int32_t CONTENTS_LADDER = 0x20000000;
    constexpr std::int32_t CONTENTS_HITBOX = 0x40000000;  // use accurate hitboxes on trace

    // everyhting
    constexpr std::int32_t MASK_ALL = 0xFFFFFFFF;
    // everything that is normally solid
    constexpr std::int32_t MASK_SOLID = CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_WINDOW | CONTENTS_MONSTER | CONTENTS_GRATE;
    // everything that blocks player movement
    constexpr std::int32_t MASK_PLAYERSOLID = CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_PLAYERCLIP | CONTENTS_WINDOW | CONTENTS_MONSTER | CONTENTS_GRATE;
    // blocks npc movement
    constexpr std::int32_t MASK_NPCSOLID = CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_MONSTERCLIP | CONTENTS_WINDOW | CONTENTS_MONSTER | CONTENTS_GRATE;
    // water physics in these contents
    constexpr std::int32_t MASK_WATER = CONTENTS_WATER | CONTENTS_MOVEABLE | CONTENTS_SLIME;
    // everything that blocks line of sight
    constexpr std::int32_t MASK_OPAQUE = CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_SLIME | CONTENTS_OPAQUE;
    // bullets see these as solid
    constexpr std::int32_t MASK_SHOT = CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_MONSTER | CONTENTS_WINDOW | CONTENTS_DEBRIS | CONTENTS_HITBOX;
    // non-raycasted weapons see this as solid (includes grates)
    constexpr std::int32_t MASK_SHOT_HULL = CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_MONSTER | CONTENTS_WINDOW | CONTENTS_DEBRIS | CONTENTS_GRATE;
    // everything normally solid, except monsters (world+brush only)
    constexpr std::int32_t MASK_SOLID_BRUSHONLY = CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_WINDOW | CONTENTS_GRATE;
    // everything normally solid for player movement, except monsters (world+brush only)
    constexpr std::int32_t MASK_PLAYERSOLID_BRUSHONLY = CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_WINDOW | CONTENTS_PLAYERCLIP | CONTENTS_GRATE;
    // everything normally solid for npc movement, except monsters (world+brush only)
    constexpr std::int32_t MASK_NPCSOLID_BRUSHONLY = CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_WINDOW | CONTENTS_MONSTERCLIP | CONTENTS_GRATE;
    // just the world, used for route rebuilding
    constexpr std::int32_t MASK_NPCWORLDSTATIC = CONTENTS_SOLID | CONTENTS_WINDOW | CONTENTS_MONSTERCLIP | CONTENTS_GRATE;
    // UNDONE: This is untested, any moving water
    constexpr std::int32_t MASK_CURRENT = CONTENTS_CURRENT_0 | CONTENTS_CURRENT_90 | CONTENTS_CURRENT_180 | CONTENTS_CURRENT_270 | CONTENTS_CURRENT_UP | CONTENTS_CURRENT_DOWN;
    constexpr std::int32_t MASK_DEADSOLID = CONTENTS_SOLID | CONTENTS_PLAYERCLIP | CONTENTS_WINDOW | CONTENTS_GRATE;

    enum class lump_index
        : std::size_t
    {
        entities = 0,
        planes = 1,
        tex_data = 2,
        vertices = 3, // "LUMP_VERTEXES"
        visibility = 4,
        nodes = 5,
        tex_info = 6,
        faces = 7,
        lighting = 8,
        occlusion = 9,
        leafs = 10,
        edges = 12,
        surfedges = 13,
        models = 14,
        world_lights = 15,
        leaf_faces = 16,
        leaf_brushes = 17,
        brushes = 18,
        brush_sides = 19,
        ares = 20,
        area_portals = 21,
        portals = 22,
        clusters = 23,
        portal_verts = 24,
        cluster_portals = 25,
        disp_info = 26,
        original_faces = 27,
        phys_collide = 29,
        vert_normals = 30,
        vert_normal_indices = 31,
        lightmap_alphas = 32,
        disp_verts = 33,
        disp_lightmap_sample_positions = 34,
        game_lump = 35,
        leafwaterdata = 36,
        primitives = 37,
        prim_vertices = 38,
        prim_indices = 39,
        pak_file = 40,
        clipportal_vertices = 41,
        cubemaps = 42,
        texdata_string_data = 43,
        texdata_string_table = 44,
        overlays = 45,
        leaf_min_dist_to_water = 46,
        face_macro_texture_info = 47,
        disp_tris = 48
    };

    class lump_t
    {
        using type_four_cc = std::array<char, 4>;
    public:
        std::int32_t file_offset = 0; // 0x0
        std::int32_t file_size = 0; // 0x4
        std::int32_t version = 0; // 0x8
        type_four_cc four_cc{};    // 0xC
    };//Size=0x10

    class dheader_t
    {
        using type_lumps = std::array<lump_t, HEADER_LUMPS>;

    public:
        std::int32_t ident = 0; // 0x000
        std::int32_t version = 0; // 0x004
        type_lumps   lumps{};          // 0x008
        std::int32_t map_revision = 0; // 0x408

    };//Size=0x40C

    class dplane_t
    {
    public:
        vector3      normal;   // 0x00
        float        distance; // 0x0C
        std::int32_t type;     // 0x10
    };//Size=0x14

    class cplane_t
    {
    public:
        vector3      normal;            // 0x00
        float        distance;          // 0x0C
        std::uint8_t type;              // 0x10
        std::uint8_t sign_bits;         // 0x11
    private:
        std::uint8_t _pad0x12[0x2]{}; // 0x12
    };//Size=0x14

    class dedge_t
    {
    public:
        std::array<std::uint16_t, 2> v; // 0x0
    };//Size=0x4

    class mvertex_t
    {
    public:
        vector3 position; // 0x0
    };//Size=0xC

    class dleaf_t
    {
        using type_min_max = std::array<std::int16_t, 3>;

    public:
        std::int32_t  contents;           // 0x00
        std::int16_t  cluster;            // 0x04
        std::int16_t  area : 9;           // 0x06
        std::int16_t  flags : 7;          // 0x11
        type_min_max  mins;               // 0x1A
        type_min_max  maxs;               // 0x20
        std::uint16_t first_leafface;     // 0x26
        std::uint16_t num_leaffaces;      // 0x28
        std::uint16_t first_leafbrush;    // 0x2A
        std::uint16_t num_leafbrushes;    // 0x2C
        std::int16_t  leaf_water_data_id; // 0x2E
    };//Size=0x30

    class dnode_t
    {
        using type_min_max = std::array<std::int16_t, 3>;
        using type_children = std::array<std::int32_t, 2>;

    public:
        std::int32_t  plane_num;         // 0x00
        type_children children;          // 0x04
        type_min_max  mins;              // 0x0C
        type_min_max  maxs;              // 0x12
        std::uint16_t first_face;        // 0x18
        std::uint16_t num_faces;         // 0x1A
        std::int16_t  area;              // 0x1C
    private:
        std::uint8_t  _pad0x1E[0x2]{}; // 0x1E
    };//Size=0x20

    class snode_t
    {
        using type_min_max = std::array<std::int16_t, 3>;
        using type_children = std::array<std::int32_t, 2>;

    public:
        std::int32_t  plane_num;           // 0x00
        cplane_t* plane;               // 0x04
        type_children children;            // 0x08
        dleaf_t* leaf_children;       // 0x10
        snode_t* node_children;       // 0x14
        type_min_max  mins;                // 0x18
        type_min_max  maxs;                // 0x1E
        std::uint16_t first_face;          // 0x24
        std::uint16_t num_faces;           // 0x26
        std::int16_t  area;                // 0x28
    private:
        std::uint8_t  _pad0x2A[0x2]{};   // 0x2A
    };//Size=0x2C

    class dface_t
    {
        using type_styles = std::array<std::uint8_t, 4>;
        using type_luxels = std::array<std::int32_t, 2>;

    public:
        std::uint16_t plane_num;                       // 0x00
        std::uint8_t  side;                            // 0x02
        std::uint8_t  on_node;                         // 0x03
        std::int32_t  first_edge;                      // 0x04
        std::int16_t  num_edges;                       // 0x08
        std::int16_t  tex_info;                        // 0x0A
        std::int16_t  disp_info;                       // 0x0C
        std::int16_t  surface_fog_volume_id;           // 0x0E
        type_styles   styles;                          // 0x10
        std::int32_t  light_offset;                    // 0x18
        float         area;                            // 0x1C
        type_luxels   lightmap_texture_mins_in_luxels; // 0x20
        type_luxels   lightmap_texture_size_in_luxels; // 0x28
        std::int32_t  orig_face;                       // 0x30
        std::uint16_t num_prims;                       // 0x34
        std::uint16_t first_prim_id;                   // 0x36
        std::uint16_t smoothing_groups;                // 0x38
    };//Size=0x3A

    class dbrush_t
    {
    public:
        std::int32_t first_side; // 0x0
        std::int32_t num_sides;  // 0x4
        std::int32_t contents;   // 0x8
    };//Size=0xC

    class dbrushside_t
    {
    public:
        std::uint16_t plane_num; // 0x0
        std::int16_t  tex_info;  // 0x2
        std::int16_t  disp_info; // 0x4
        std::uint8_t  bevel;     // 0x6
        std::uint8_t  thin;      // 0x7
    };//Size=0x8

    class texinfo_t
    {
        using type_vecs = std::array<vector4, 2>;

    public:
        type_vecs    texture_vecs;  // 0x00
        type_vecs    lightmap_vecs; // 0x20
        std::int32_t flags;         // 0x40
        std::int32_t tex_data;      // 0x44
    };//Size=0x48

    class VPlane
    {
    public:
        VPlane() = default;

        VPlane(
            const vector3& origin,
            const float distance
            )
            : origin(origin)
            , distance(distance)
        { }

        VPlane(
            const VPlane& rhs
            ) = default;

        VPlane(
            VPlane&& rhs
            ) noexcept
        {
            *this = std::move(rhs);
        }

        VPlane& operator = (
            const VPlane& rhs
            ) = default;

        VPlane& operator = (
            VPlane&& rhs
            ) noexcept
        {
            origin = std::move(rhs.origin);
            distance = rhs.distance;

            rhs.distance = 0.f;

            return *this;
        }

        _NODISCARD
            float dist(
                const vector3& destination
                ) const
        {
            return origin.dot(destination) - distance;
        }

        void init(
            const vector3& origin,
            const float distance
            )
        {
            this->origin = origin;
            this->distance = distance;
        }

    public:
        vector3 origin = 0.f;
        float   distance = 0.f;
    };

    class polygon
    {
        using type_surfinfo_vecs = std::array<vector3, MAX_SURFINFO_VERTS>;
        using type_edge_planes = std::array<VPlane, MAX_SURFINFO_VERTS>;

    public:
        type_surfinfo_vecs verts;
        std::size_t        num_verts = 0;
        VPlane             plane;
        type_edge_planes   edge_planes;
        type_surfinfo_vecs vec2d;
        std::int32_t       skip = 0;
    };

    struct trace_t
    {
        /// <summary>
        /// Determine if a plan is NOT valid
        /// </summary>
        bool         all_solid = true;
        /// <summary>
        /// Determine if the start point was in a solid area
        /// </summary>
        bool         start_solid = true;
        /// <summary>
        /// Time completed, 1.0              = didn't hit anything
        /// </summary>
        float        fraction = 1.f;
        float        fraction_left_solid = 1.f;
        /// <summary>
        /// Final trace position
        /// </summary>
        vector3      end_pos;
        std::int32_t contents = 0;
        dbrush_t* brush = nullptr;
        std::int32_t num_brush_sides = 0;

        void clear()
        {
            all_solid = true;
            start_solid = true;
            fraction = 1.f;
            fraction_left_solid = 1.f;
            contents = 0;
            brush = nullptr;
            num_brush_sides = 0;
            end_pos.clear();
        }
    };
}
