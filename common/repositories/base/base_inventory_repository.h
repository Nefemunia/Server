/**
 * DO NOT MODIFY THIS FILE
 *
 * This repository was automatically generated and is NOT to be modified directly.
 * Any repository modifications are meant to be made to the repository extending the base.
 * Any modifications to base repositories are to be made by the generator only
 *
 * @generator ./utils/scripts/generators/repository-generator.pl
 * @docs https://eqemu.gitbook.io/server/in-development/developer-area/repositories
 */

#ifndef EQEMU_BASE_INVENTORY_REPOSITORY_H
#define EQEMU_BASE_INVENTORY_REPOSITORY_H

#include "../../database.h"
#include "../../strings.h"
#include <ctime>

class BaseInventoryRepository {
public:
	struct Inventory {
		int         charid;
		int         slotid;
		int         itemid;
		int         charges;
		int         color;
		int         augslot1;
		int         augslot2;
		int         augslot3;
		int         augslot4;
		int         augslot5;
		int         augslot6;
		int         instnodrop;
		std::string custom_data;
		int         ornamenticon;
		int         ornamentidfile;
		int         ornament_hero_model;
	};

	static std::string PrimaryKey()
	{
		return std::string("charid");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"charid",
			"slotid",
			"itemid",
			"charges",
			"color",
			"augslot1",
			"augslot2",
			"augslot3",
			"augslot4",
			"augslot5",
			"augslot6",
			"instnodrop",
			"custom_data",
			"ornamenticon",
			"ornamentidfile",
			"ornament_hero_model",
		};
	}

	static std::vector<std::string> SelectColumns()
	{
		return {
			"charid",
			"slotid",
			"itemid",
			"charges",
			"color",
			"augslot1",
			"augslot2",
			"augslot3",
			"augslot4",
			"augslot5",
			"augslot6",
			"instnodrop",
			"custom_data",
			"ornamenticon",
			"ornamentidfile",
			"ornament_hero_model",
		};
	}

	static std::string ColumnsRaw()
	{
		return std::string(Strings::Implode(", ", Columns()));
	}

	static std::string SelectColumnsRaw()
	{
		return std::string(Strings::Implode(", ", SelectColumns()));
	}

	static std::string TableName()
	{
		return std::string("inventory");
	}

	static std::string BaseSelect()
	{
		return fmt::format(
			"SELECT {} FROM {}",
			SelectColumnsRaw(),
			TableName()
		);
	}

	static std::string BaseInsert()
	{
		return fmt::format(
			"INSERT INTO {} ({}) ",
			TableName(),
			ColumnsRaw()
		);
	}

	static Inventory NewEntity()
	{
		Inventory entry{};

		entry.charid              = 0;
		entry.slotid              = 0;
		entry.itemid              = 0;
		entry.charges             = 0;
		entry.color               = 0;
		entry.augslot1            = 0;
		entry.augslot2            = 0;
		entry.augslot3            = 0;
		entry.augslot4            = 0;
		entry.augslot5            = 0;
		entry.augslot6            = 0;
		entry.instnodrop          = 0;
		entry.custom_data         = "";
		entry.ornamenticon        = 0;
		entry.ornamentidfile      = 0;
		entry.ornament_hero_model = 0;

		return entry;
	}

	static Inventory GetInventoryEntry(
		const std::vector<Inventory> &inventorys,
		int inventory_id
	)
	{
		for (auto &inventory : inventorys) {
			if (inventory.charid == inventory_id) {
				return inventory;
			}
		}

		return NewEntity();
	}

	static Inventory FindOne(
		Database& db,
		int inventory_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE id = {} LIMIT 1",
				BaseSelect(),
				inventory_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			Inventory entry{};

			entry.charid              = atoi(row[0]);
			entry.slotid              = atoi(row[1]);
			entry.itemid              = atoi(row[2]);
			entry.charges             = atoi(row[3]);
			entry.color               = atoi(row[4]);
			entry.augslot1            = atoi(row[5]);
			entry.augslot2            = atoi(row[6]);
			entry.augslot3            = atoi(row[7]);
			entry.augslot4            = atoi(row[8]);
			entry.augslot5            = atoi(row[9]);
			entry.augslot6            = atoi(row[10]);
			entry.instnodrop          = atoi(row[11]);
			entry.custom_data         = row[12] ? row[12] : "";
			entry.ornamenticon        = atoi(row[13]);
			entry.ornamentidfile      = atoi(row[14]);
			entry.ornament_hero_model = atoi(row[15]);

			return entry;
		}

		return NewEntity();
	}

	static int DeleteOne(
		Database& db,
		int inventory_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				inventory_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		Database& db,
		Inventory inventory_entry
	)
	{
		std::vector<std::string> update_values;

		auto columns = Columns();

		update_values.push_back(columns[0] + " = " + std::to_string(inventory_entry.charid));
		update_values.push_back(columns[1] + " = " + std::to_string(inventory_entry.slotid));
		update_values.push_back(columns[2] + " = " + std::to_string(inventory_entry.itemid));
		update_values.push_back(columns[3] + " = " + std::to_string(inventory_entry.charges));
		update_values.push_back(columns[4] + " = " + std::to_string(inventory_entry.color));
		update_values.push_back(columns[5] + " = " + std::to_string(inventory_entry.augslot1));
		update_values.push_back(columns[6] + " = " + std::to_string(inventory_entry.augslot2));
		update_values.push_back(columns[7] + " = " + std::to_string(inventory_entry.augslot3));
		update_values.push_back(columns[8] + " = " + std::to_string(inventory_entry.augslot4));
		update_values.push_back(columns[9] + " = " + std::to_string(inventory_entry.augslot5));
		update_values.push_back(columns[10] + " = " + std::to_string(inventory_entry.augslot6));
		update_values.push_back(columns[11] + " = " + std::to_string(inventory_entry.instnodrop));
		update_values.push_back(columns[12] + " = '" + Strings::Escape(inventory_entry.custom_data) + "'");
		update_values.push_back(columns[13] + " = " + std::to_string(inventory_entry.ornamenticon));
		update_values.push_back(columns[14] + " = " + std::to_string(inventory_entry.ornamentidfile));
		update_values.push_back(columns[15] + " = " + std::to_string(inventory_entry.ornament_hero_model));

		auto results = db.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				Strings::Implode(", ", update_values),
				PrimaryKey(),
				inventory_entry.charid
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static Inventory InsertOne(
		Database& db,
		Inventory inventory_entry
	)
	{
		std::vector<std::string> insert_values;

		insert_values.push_back(std::to_string(inventory_entry.charid));
		insert_values.push_back(std::to_string(inventory_entry.slotid));
		insert_values.push_back(std::to_string(inventory_entry.itemid));
		insert_values.push_back(std::to_string(inventory_entry.charges));
		insert_values.push_back(std::to_string(inventory_entry.color));
		insert_values.push_back(std::to_string(inventory_entry.augslot1));
		insert_values.push_back(std::to_string(inventory_entry.augslot2));
		insert_values.push_back(std::to_string(inventory_entry.augslot3));
		insert_values.push_back(std::to_string(inventory_entry.augslot4));
		insert_values.push_back(std::to_string(inventory_entry.augslot5));
		insert_values.push_back(std::to_string(inventory_entry.augslot6));
		insert_values.push_back(std::to_string(inventory_entry.instnodrop));
		insert_values.push_back("'" + Strings::Escape(inventory_entry.custom_data) + "'");
		insert_values.push_back(std::to_string(inventory_entry.ornamenticon));
		insert_values.push_back(std::to_string(inventory_entry.ornamentidfile));
		insert_values.push_back(std::to_string(inventory_entry.ornament_hero_model));

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				Strings::Implode(",", insert_values)
			)
		);

		if (results.Success()) {
			inventory_entry.charid = results.LastInsertedID();
			return inventory_entry;
		}

		inventory_entry = NewEntity();

		return inventory_entry;
	}

	static int InsertMany(
		Database& db,
		std::vector<Inventory> inventory_entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &inventory_entry: inventory_entries) {
			std::vector<std::string> insert_values;

			insert_values.push_back(std::to_string(inventory_entry.charid));
			insert_values.push_back(std::to_string(inventory_entry.slotid));
			insert_values.push_back(std::to_string(inventory_entry.itemid));
			insert_values.push_back(std::to_string(inventory_entry.charges));
			insert_values.push_back(std::to_string(inventory_entry.color));
			insert_values.push_back(std::to_string(inventory_entry.augslot1));
			insert_values.push_back(std::to_string(inventory_entry.augslot2));
			insert_values.push_back(std::to_string(inventory_entry.augslot3));
			insert_values.push_back(std::to_string(inventory_entry.augslot4));
			insert_values.push_back(std::to_string(inventory_entry.augslot5));
			insert_values.push_back(std::to_string(inventory_entry.augslot6));
			insert_values.push_back(std::to_string(inventory_entry.instnodrop));
			insert_values.push_back("'" + Strings::Escape(inventory_entry.custom_data) + "'");
			insert_values.push_back(std::to_string(inventory_entry.ornamenticon));
			insert_values.push_back(std::to_string(inventory_entry.ornamentidfile));
			insert_values.push_back(std::to_string(inventory_entry.ornament_hero_model));

			insert_chunks.push_back("(" + Strings::Implode(",", insert_values) + ")");
		}

		std::vector<std::string> insert_values;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES {}",
				BaseInsert(),
				Strings::Implode(",", insert_chunks)
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static std::vector<Inventory> All(Database& db)
	{
		std::vector<Inventory> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			Inventory entry{};

			entry.charid              = atoi(row[0]);
			entry.slotid              = atoi(row[1]);
			entry.itemid              = atoi(row[2]);
			entry.charges             = atoi(row[3]);
			entry.color               = atoi(row[4]);
			entry.augslot1            = atoi(row[5]);
			entry.augslot2            = atoi(row[6]);
			entry.augslot3            = atoi(row[7]);
			entry.augslot4            = atoi(row[8]);
			entry.augslot5            = atoi(row[9]);
			entry.augslot6            = atoi(row[10]);
			entry.instnodrop          = atoi(row[11]);
			entry.custom_data         = row[12] ? row[12] : "";
			entry.ornamenticon        = atoi(row[13]);
			entry.ornamentidfile      = atoi(row[14]);
			entry.ornament_hero_model = atoi(row[15]);

			all_entries.push_back(entry);
		}

		return all_entries;
	}

	static std::vector<Inventory> GetWhere(Database& db, std::string where_filter)
	{
		std::vector<Inventory> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {}",
				BaseSelect(),
				where_filter
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			Inventory entry{};

			entry.charid              = atoi(row[0]);
			entry.slotid              = atoi(row[1]);
			entry.itemid              = atoi(row[2]);
			entry.charges             = atoi(row[3]);
			entry.color               = atoi(row[4]);
			entry.augslot1            = atoi(row[5]);
			entry.augslot2            = atoi(row[6]);
			entry.augslot3            = atoi(row[7]);
			entry.augslot4            = atoi(row[8]);
			entry.augslot5            = atoi(row[9]);
			entry.augslot6            = atoi(row[10]);
			entry.instnodrop          = atoi(row[11]);
			entry.custom_data         = row[12] ? row[12] : "";
			entry.ornamenticon        = atoi(row[13]);
			entry.ornamentidfile      = atoi(row[14]);
			entry.ornament_hero_model = atoi(row[15]);

			all_entries.push_back(entry);
		}

		return all_entries;
	}

	static int DeleteWhere(Database& db, std::string where_filter)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {}",
				TableName(),
				where_filter
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int Truncate(Database& db)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"TRUNCATE TABLE {}",
				TableName()
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

};

#endif //EQEMU_BASE_INVENTORY_REPOSITORY_H
