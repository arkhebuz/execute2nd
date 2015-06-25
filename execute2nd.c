/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */


#include <geanyplugin.h>

GeanyPlugin     *geany_plugin;
GeanyData       *geany_data;
GeanyFunctions  *geany_functions;
GeanyKeyGroup   *plugin_key_group;

PLUGIN_VERSION_CHECK(211)
PLUGIN_SET_INFO("Execute 2nd", "Keybind 2nd execute entry in the build menu",
                "1.0", "Arkhebuz");

/* Command index (starts from 0) */
#define COMMAND_NUM 1

enum
{
    EXECUTE2ND_EXECUTE,
};


/* Keybinded function */
void execute2nd()
{
    /* Select execute_group from GeanyBuildGroup's */
    GeanyBuildGroup execute_group = GEANY_GBG_EXEC;

    /* Select entry_label from GeanyBuildCmdEntries */
    GeanyBuildCmdEntries entry_label = GEANY_BC_LABEL;

    /* Get COMMAND_NUM entry_label (returns NULL if entry doesn't exist) */
    const gchar* command_label;
    command_label = build_get_current_menu_item(execute_group, COMMAND_NUM, entry_label);

    if (command_label != NULL)
    {
        build_activate_menu_item(execute_group, COMMAND_NUM);
    }
}


void plugin_init(GeanyData *data)
{
    /* Create execute2nd keybind item */
    plugin_key_group = plugin_set_key_group(geany_plugin, "execute2nd", 1, NULL);
    keybindings_set_item(plugin_key_group, EXECUTE2ND_EXECUTE, execute2nd,
                         0, 0, "build_run2", _("run2"), NULL);
}

void plugin_cleanup(void)
{
}
