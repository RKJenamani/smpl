#include <sbpl_arm_planner/visualize.h>

#include <mutex>

namespace sbpl {
namespace viz {

static VisualizerBase* g_visualizer;

void set_visualizer(VisualizerBase* visualizer)
{
    g_visualizer = visualizer;
}

void unset_visualizer()
{
    g_visualizer = nullptr;
}

void visualize(
    levels::Level level,
    const visualization_msgs::MarkerArray& markers)
{
    if (!g_visualizer) {
        return;
    }
    g_visualizer->visualize(level, markers);

}

} // namespace viz
} // namespace sbpl
