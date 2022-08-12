#include <iostream>
#include <string>
#include <unistd.h>
#include <dpp/dpp.h>

#include <token.h>

using std::string;

int main(int argc, char const *argv[1])
{
    dpp::cluster bot(token);

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>())
        {
            bot.message_create(dpp::message(1007034488393572534, "UwU!"));
 
                    
            bot.global_command_create(dpp::slashcommand("UwU", "UwU!", bot.me.id));
            bot.global_command_create(dpp::slashcommand("lud", "zrobie ci louda!", bot.me.id));

            std::cout << "\033[1;32mOn\033[0m\n";
        }
    });
    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event)
    {
        if      (event.command.get_command_name() == "UwU!")
        {
            event.reply("sex!");
        }
        if (event.command.get_command_name() == "lud");
        {   
            event.reply(dpp::message(event.command.channel_id, "Okej kocie :3"));
            sleep(3);
            bot.message_create(dpp::message(event.command.channel_id, "*klęką przed nim*"));
            sleep(2);
            bot.message_create(dpp::message(event.command.channel_id, "*zaczyna ssać mu pałe* :eggplant:"));
            sleep(5);
            bot.message_create(dpp::message(event.command.channel_id, "*wypluwa* :weary:"));
        }
    });


    bot.on_message_create([&bot](const dpp::message_create_t & event) {
        if (event.msg.content == "UwU")
        {
            bot.message_create(dpp::message(event.msg.channel_id, "UwU!").set_reference(event.msg.id));
        }
        else if (event.msg.content == "chce loda")
        {
            event.reply(dpp::message(event.msg.channel_id, "Okej kocie :3").set_reference(event.msg.id));
            sleep(3);
            bot.message_create(dpp::message(event.msg.channel_id, "*klęką przed nim*").set_reference(event.msg.id));
            sleep(2);
            bot.message_create(dpp::message(event.msg.channel_id, "*zaczyna ssać mu pałe* :eggplant:").set_reference(event.msg.id));
            sleep(5);
            bot.message_create(dpp::message(event.msg.channel_id, "*wypluwa* :weary:").set_reference(event.msg.id));
        }
    });
	  
 
 
    bot.start(dpp::st_wait);
}
