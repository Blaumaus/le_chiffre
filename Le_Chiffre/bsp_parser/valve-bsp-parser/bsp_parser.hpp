///--------------------------------------------------------------------------------
///-- Author        ReactiioN
///-- Copyright     2016-2020, ReactiioN
///-- License       MIT
///--------------------------------------------------------------------------------
#pragma once

#include "core/valve_structs.hpp"
#include <shared_mutex>

namespace rn {
    class bsp_parser final
    {
    public:
        bsp_parser() = default;

        ~bsp_parser() = default;

        bsp_parser(
            const bsp_parser& rhs
            ) = delete;

        bsp_parser& operator = (
            const bsp_parser& rhs
            ) = delete;

        bsp_parser(
            bsp_parser&& rhs
            ) noexcept;

        bsp_parser& operator = (
            bsp_parser&& rhs
            ) noexcept;

    private:
        bool set_current_map(
            const std::string& directory,
            const std::string& map_name,
            std::string& file_path
            );

        bool parse_planes(
            std::ifstream& file
            );

        bool parse_nodes(
            std::ifstream& file
            );

        bool parse_leaffaces(
            std::ifstream& file
            );

        bool parse_leafbrushes(
            std::ifstream& file
            );

        bool parse_polygons();

        void ray_cast_node(
            std::int32_t    node_index,
            float           start_fraction,
            float           end_fraction,
            const vector3& origin,
            const vector3& destination,
            valve::trace_t* out
            );

        void ray_cast_surface(
            std::int32_t    surface_index,
            const vector3& origin,
            const vector3& destination,
            valve::trace_t* out
            );

        void ray_cast_brush(
            valve::dbrush_t* brush,
            const vector3& origin,
            const vector3& destination,
            valve::trace_t* out
            )const;

        template<typename type>
        _NODISCARD
            bool parse_lump(
                std::ifstream& file,
                const valve::lump_index lump_index,
                std::vector<type>& out
                ) const
        {
            const auto index = static_cast<std::underlying_type_t<valve::lump_index>>(lump_index);
            if (index >= _bsp_header.lumps.size()) {
                return false;
            }

            const auto& lump = _bsp_header.lumps.at(index);
            const auto size = static_cast<std::size_t>(lump.file_size) / sizeof(type);

            out.resize(size);

            file.seekg(lump.file_offset);
            file.read(reinterpret_cast<char*>(out.data()), size * static_cast<std::size_t>(sizeof(type)));

            return true;
        }

    public:
        bool load_map(
            const std::string& directory,
            const std::string& map_name
            );

        bool is_visible(
            const vector3& origin,
            const vector3& destination
            );

        void trace_ray(
            const vector3& origin,
            const vector3 & final,
            valve::trace_t* out
            );

    private:
        std::string                      _map_name;
        valve::dheader_t                 _bsp_header;
        std::vector<valve::mvertex_t>    _vertices;
        std::vector<valve::cplane_t>     _planes;
        std::vector<valve::dedge_t>      _edges;
        std::vector<std::int32_t>        _surf_edges;
        std::vector<valve::dleaf_t>      _leaves;
        std::vector<valve::snode_t>      _nodes;
        std::vector<valve::dface_t>      _surfaces;
        std::vector<valve::texinfo_t>    _tex_infos;
        std::vector<valve::dbrush_t>     _brushes;
        std::vector<valve::dbrushside_t> _brush_sides;
        std::vector<std::uint16_t>       _leaf_faces;
        std::vector<std::uint16_t>       _leaf_brushes;
        std::vector<valve::polygon>      _polygons;
        mutable std::shared_timed_mutex  _mutex;
    };
}
