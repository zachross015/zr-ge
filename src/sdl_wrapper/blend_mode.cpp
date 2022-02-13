#include <sdl_wrapper/blend_mode.h>

namespace zr {

    std::vector<blend_mode> all_blend_modes() {
        const blend_mode all[] = {
            blend_mode::none,
            blend_mode::blend,
            blend_mode::add,
            blend_mode::mod
        };
        return std::vector<blend_mode>(all, all + sizeof(all) / sizeof(blend_mode));
    }


    std::ostream& operator<<(std::ostream& out, const blend_mode& ws) {
        const char* s = 0;
#define CV(v) case(blend_mode::v): s = #v; break;
        switch (ws) {
            CV(none)
            CV(blend)
            CV(add)
            CV(mod)
        }       
#undef CV
        out << s;
        return out;
    }

}
