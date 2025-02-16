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

#ifndef EQEMU_BASE_SPAWN2_REPOSITORY_H
#define EQEMU_BASE_SPAWN2_REPOSITORY_H

#include "../../database.h"
#include "../../strings.h"
#include <ctime>

class BaseSpawn2Repository {
public:
	struct Spawn2 {
		int         id;
		int         spawngroupID;
		std::string zone;
		int         version;
		float       x;
		float       y;
		float       z;
		float       heading;
		int         respawntime;
		int         variance;
		int         pathgrid;
		int         path_when_zone_idle;
		int         _condition;
		int         cond_value;
		int         enabled;
		int         animation;
		int         min_expansion;
		int         max_expansion;
		std::string content_flags;
		std::string content_flags_disabled;
	};

	static std::string PrimaryKey()
	{
		return std::string("id");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"id",
			"spawngroupID",
			"zone",
			"version",
			"x",
			"y",
			"z",
			"heading",
			"respawntime",
			"variance",
			"pathgrid",
			"path_when_zone_idle",
			"_condition",
			"cond_value",
			"enabled",
			"animation",
			"min_expansion",
			"max_expansion",
			"content_flags",
			"content_flags_disabled",
		};
	}

	static std::vector<std::string> SelectColumns()
	{
		return {
			"id",
			"spawngroupID",
			"zone",
			"version",
			"x",
			"y",
			"z",
			"heading",
			"respawntime",
			"variance",
			"pathgrid",
			"path_when_zone_idle",
			"_condition",
			"cond_value",
			"enabled",
			"animation",
			"min_expansion",
			"max_expansion",
			"content_flags",
			"content_flags_disabled",
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
		return std::string("spawn2");
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

	static Spawn2 NewEntity()
	{
		Spawn2 entry{};

		entry.id                     = 0;
		entry.spawngroupID           = 0;
		entry.zone                   = "";
		entry.version                = 0;
		entry.x                      = 0.000000;
		entry.y                      = 0.000000;
		entry.z                      = 0.000000;
		entry.heading                = 0.000000;
		entry.respawntime            = 0;
		entry.variance               = 0;
		entry.pathgrid               = 0;
		entry.path_when_zone_idle    = 0;
		entry._condition             = 0;
		entry.cond_value             = 1;
		entry.enabled                = 1;
		entry.animation              = 0;
		entry.min_expansion          = -1;
		entry.max_expansion          = -1;
		entry.content_flags          = "";
		entry.content_flags_disabled = "";

		return entry;
	}

	static Spawn2 GetSpawn2Entry(
		const std::vector<Spawn2> &spawn2s,
		int spawn2_id
	)
	{
		for (auto &spawn2 : spawn2s) {
			if (spawn2.id == spawn2_id) {
				return spawn2;
			}
		}

		return NewEntity();
	}

	static Spawn2 FindOne(
		Database& db,
		int spawn2_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE id = {} LIMIT 1",
				BaseSelect(),
				spawn2_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			Spawn2 entry{};

			entry.id                     = atoi(row[0]);
			entry.spawngroupID           = atoi(row[1]);
			entry.zone                   = row[2] ? row[2] : "";
			entry.version                = atoi(row[3]);
			entry.x                      = static_cast<float>(atof(row[4]));
			entry.y                      = static_cast<float>(atof(row[5]));
			entry.z                      = static_cast<float>(atof(row[6]));
			entry.heading                = static_cast<float>(atof(row[7]));
			entry.respawntime            = atoi(row[8]);
			entry.variance               = atoi(row[9]);
			entry.pathgrid               = atoi(row[10]);
			entry.path_when_zone_idle    = atoi(row[11]);
			entry._condition             = atoi(row[12]);
			entry.cond_value             = atoi(row[13]);
			entry.enabled                = atoi(row[14]);
			entry.animation              = atoi(row[15]);
			entry.min_expansion          = atoi(row[16]);
			entry.max_expansion          = atoi(row[17]);
			entry.content_flags          = row[18] ? row[18] : "";
			entry.content_flags_disabled = row[19] ? row[19] : "";

			return entry;
		}

		return NewEntity();
	}

	static int DeleteOne(
		Database& db,
		int spawn2_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				spawn2_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		Database& db,
		Spawn2 spawn2_entry
	)
	{
		std::vector<std::string> update_values;

		auto columns = Columns();

		update_values.push_back(columns[1] + " = " + std::to_string(spawn2_entry.spawngroupID));
		update_values.push_back(columns[2] + " = '" + Strings::Escape(spawn2_entry.zone) + "'");
		update_values.push_back(columns[3] + " = " + std::to_string(spawn2_entry.version));
		update_values.push_back(columns[4] + " = " + std::to_string(spawn2_entry.x));
		update_values.push_back(columns[5] + " = " + std::to_string(spawn2_entry.y));
		update_values.push_back(columns[6] + " = " + std::to_string(spawn2_entry.z));
		update_values.push_back(columns[7] + " = " + std::to_string(spawn2_entry.heading));
		update_values.push_back(columns[8] + " = " + std::to_string(spawn2_entry.respawntime));
		update_values.push_back(columns[9] + " = " + std::to_string(spawn2_entry.variance));
		update_values.push_back(columns[10] + " = " + std::to_string(spawn2_entry.pathgrid));
		update_values.push_back(columns[11] + " = " + std::to_string(spawn2_entry.path_when_zone_idle));
		update_values.push_back(columns[12] + " = " + std::to_string(spawn2_entry._condition));
		update_values.push_back(columns[13] + " = " + std::to_string(spawn2_entry.cond_value));
		update_values.push_back(columns[14] + " = " + std::to_string(spawn2_entry.enabled));
		update_values.push_back(columns[15] + " = " + std::to_string(spawn2_entry.animation));
		update_values.push_back(columns[16] + " = " + std::to_string(spawn2_entry.min_expansion));
		update_values.push_back(columns[17] + " = " + std::to_string(spawn2_entry.max_expansion));
		update_values.push_back(columns[18] + " = '" + Strings::Escape(spawn2_entry.content_flags) + "'");
		update_values.push_back(columns[19] + " = '" + Strings::Escape(spawn2_entry.content_flags_disabled) + "'");

		auto results = db.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				Strings::Implode(", ", update_values),
				PrimaryKey(),
				spawn2_entry.id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static Spawn2 InsertOne(
		Database& db,
		Spawn2 spawn2_entry
	)
	{
		std::vector<std::string> insert_values;

		insert_values.push_back(std::to_string(spawn2_entry.id));
		insert_values.push_back(std::to_string(spawn2_entry.spawngroupID));
		insert_values.push_back("'" + Strings::Escape(spawn2_entry.zone) + "'");
		insert_values.push_back(std::to_string(spawn2_entry.version));
		insert_values.push_back(std::to_string(spawn2_entry.x));
		insert_values.push_back(std::to_string(spawn2_entry.y));
		insert_values.push_back(std::to_string(spawn2_entry.z));
		insert_values.push_back(std::to_string(spawn2_entry.heading));
		insert_values.push_back(std::to_string(spawn2_entry.respawntime));
		insert_values.push_back(std::to_string(spawn2_entry.variance));
		insert_values.push_back(std::to_string(spawn2_entry.pathgrid));
		insert_values.push_back(std::to_string(spawn2_entry.path_when_zone_idle));
		insert_values.push_back(std::to_string(spawn2_entry._condition));
		insert_values.push_back(std::to_string(spawn2_entry.cond_value));
		insert_values.push_back(std::to_string(spawn2_entry.enabled));
		insert_values.push_back(std::to_string(spawn2_entry.animation));
		insert_values.push_back(std::to_string(spawn2_entry.min_expansion));
		insert_values.push_back(std::to_string(spawn2_entry.max_expansion));
		insert_values.push_back("'" + Strings::Escape(spawn2_entry.content_flags) + "'");
		insert_values.push_back("'" + Strings::Escape(spawn2_entry.content_flags_disabled) + "'");

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				Strings::Implode(",", insert_values)
			)
		);

		if (results.Success()) {
			spawn2_entry.id = results.LastInsertedID();
			return spawn2_entry;
		}

		spawn2_entry = NewEntity();

		return spawn2_entry;
	}

	static int InsertMany(
		Database& db,
		std::vector<Spawn2> spawn2_entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &spawn2_entry: spawn2_entries) {
			std::vector<std::string> insert_values;

			insert_values.push_back(std::to_string(spawn2_entry.id));
			insert_values.push_back(std::to_string(spawn2_entry.spawngroupID));
			insert_values.push_back("'" + Strings::Escape(spawn2_entry.zone) + "'");
			insert_values.push_back(std::to_string(spawn2_entry.version));
			insert_values.push_back(std::to_string(spawn2_entry.x));
			insert_values.push_back(std::to_string(spawn2_entry.y));
			insert_values.push_back(std::to_string(spawn2_entry.z));
			insert_values.push_back(std::to_string(spawn2_entry.heading));
			insert_values.push_back(std::to_string(spawn2_entry.respawntime));
			insert_values.push_back(std::to_string(spawn2_entry.variance));
			insert_values.push_back(std::to_string(spawn2_entry.pathgrid));
			insert_values.push_back(std::to_string(spawn2_entry.path_when_zone_idle));
			insert_values.push_back(std::to_string(spawn2_entry._condition));
			insert_values.push_back(std::to_string(spawn2_entry.cond_value));
			insert_values.push_back(std::to_string(spawn2_entry.enabled));
			insert_values.push_back(std::to_string(spawn2_entry.animation));
			insert_values.push_back(std::to_string(spawn2_entry.min_expansion));
			insert_values.push_back(std::to_string(spawn2_entry.max_expansion));
			insert_values.push_back("'" + Strings::Escape(spawn2_entry.content_flags) + "'");
			insert_values.push_back("'" + Strings::Escape(spawn2_entry.content_flags_disabled) + "'");

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

	static std::vector<Spawn2> All(Database& db)
	{
		std::vector<Spawn2> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			Spawn2 entry{};

			entry.id                     = atoi(row[0]);
			entry.spawngroupID           = atoi(row[1]);
			entry.zone                   = row[2] ? row[2] : "";
			entry.version                = atoi(row[3]);
			entry.x                      = static_cast<float>(atof(row[4]));
			entry.y                      = static_cast<float>(atof(row[5]));
			entry.z                      = static_cast<float>(atof(row[6]));
			entry.heading                = static_cast<float>(atof(row[7]));
			entry.respawntime            = atoi(row[8]);
			entry.variance               = atoi(row[9]);
			entry.pathgrid               = atoi(row[10]);
			entry.path_when_zone_idle    = atoi(row[11]);
			entry._condition             = atoi(row[12]);
			entry.cond_value             = atoi(row[13]);
			entry.enabled                = atoi(row[14]);
			entry.animation              = atoi(row[15]);
			entry.min_expansion          = atoi(row[16]);
			entry.max_expansion          = atoi(row[17]);
			entry.content_flags          = row[18] ? row[18] : "";
			entry.content_flags_disabled = row[19] ? row[19] : "";

			all_entries.push_back(entry);
		}

		return all_entries;
	}

	static std::vector<Spawn2> GetWhere(Database& db, std::string where_filter)
	{
		std::vector<Spawn2> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {}",
				BaseSelect(),
				where_filter
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			Spawn2 entry{};

			entry.id                     = atoi(row[0]);
			entry.spawngroupID           = atoi(row[1]);
			entry.zone                   = row[2] ? row[2] : "";
			entry.version                = atoi(row[3]);
			entry.x                      = static_cast<float>(atof(row[4]));
			entry.y                      = static_cast<float>(atof(row[5]));
			entry.z                      = static_cast<float>(atof(row[6]));
			entry.heading                = static_cast<float>(atof(row[7]));
			entry.respawntime            = atoi(row[8]);
			entry.variance               = atoi(row[9]);
			entry.pathgrid               = atoi(row[10]);
			entry.path_when_zone_idle    = atoi(row[11]);
			entry._condition             = atoi(row[12]);
			entry.cond_value             = atoi(row[13]);
			entry.enabled                = atoi(row[14]);
			entry.animation              = atoi(row[15]);
			entry.min_expansion          = atoi(row[16]);
			entry.max_expansion          = atoi(row[17]);
			entry.content_flags          = row[18] ? row[18] : "";
			entry.content_flags_disabled = row[19] ? row[19] : "";

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

#endif //EQEMU_BASE_SPAWN2_REPOSITORY_H
